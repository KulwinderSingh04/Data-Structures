class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long count = 0;
        long long ans = 0;
        vector<int> v(n);
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 0; i < n; i++) {
            int rem = nums[i] % modulo;
            if(rem == k) count++;
            v[i] = count;
            ans += m[(v[i] - k) % modulo];
            m[v[i] % modulo]++;
        }
        return ans;

        return 0;
    }
};