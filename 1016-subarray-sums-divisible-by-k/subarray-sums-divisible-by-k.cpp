class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int ans = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int t = sum % k;
            if(t < 0) t += k;
            if(m.find(t) != m.end()) {
                ans += m[t];
            }
            m[t]++;
        }
        return ans;
    }
};