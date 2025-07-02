class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.size(), left = 0, mod = 1e9 + 7;
        vector<int> freq;
        for (int right = 0; right < n; ++right) {
            if (word[right] != word[left]) {
                freq.push_back(right - left);
                left = right;
            }
        }
        freq.push_back(n - left);
        int output = 1;
        for (int x : freq) {
            output = static_cast<long long>(output) * x % mod;
        }
        if (freq.size() >= k) return output;

        vector<int> prevDp(k), prevPrefixSum(k, 1);
        prevDp[0] = 1;
        for (int i = 0; i < freq.size(); ++i) {
            vector<int> newDP(k);
            for (int j = 1; j < k; ++j) {
                newDP[j] = prevPrefixSum[j - 1];
                if (j - freq[i] - 1 >= 0) {
                    newDP[j] = (newDP[j] - prevPrefixSum[j - freq[i] - 1] + mod) % mod;
                }
            }
            vector<int> newPrefixSum(k);
            newPrefixSum[0] = newDP[0];
            for (int j = 1; j < k; ++j) {
                newPrefixSum[j] = (newPrefixSum[j - 1] + newDP[j]) % mod;
            }
            prevDp = move(newDP);
            prevPrefixSum = move(newPrefixSum);
        }
        return (output - prevPrefixSum[k - 1] + mod) % mod;
    }
};