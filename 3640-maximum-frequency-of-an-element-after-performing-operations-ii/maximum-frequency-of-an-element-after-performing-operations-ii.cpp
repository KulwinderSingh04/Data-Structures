class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> diff;
        unordered_map<int, int> freq;
        int mx = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            int l = max(1, nums[i] - k);
            int r = min(nums[i] + k, mx);
            
            diff[l] += 1;
            diff[r + 1] -= 1;
            diff[nums[i]] += 0;
        }
        int cumSum = 0;
        int ans = 1;
        for(auto it = diff.begin(); it != diff.end(); it++) {
            int target = it -> first;
            it -> second += cumSum;
            int tarFreq = freq[target];
            int needCon = diff[target] - tarFreq;
            int mxPosFreq = min(numOperations, needCon);
            ans = max(ans, tarFreq + mxPosFreq);
            cumSum = it -> second;
        }
        return ans;
    }
};