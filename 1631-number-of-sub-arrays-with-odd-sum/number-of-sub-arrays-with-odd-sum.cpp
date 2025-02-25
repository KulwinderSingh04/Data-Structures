class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<int, int> m;
        int sum = 0, ans = 0;
        int n = arr.size();
        m[0] = 1;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum % 2 == 0) {
                if(m.find(1) != m.end()) ans += m[1];
            }
            else {
                if(m.find(0) != m.end()) ans += m[0];
            }
            ans %= 1000000007;
            m[sum % 2]++;
        }
        return ans;
    }
};