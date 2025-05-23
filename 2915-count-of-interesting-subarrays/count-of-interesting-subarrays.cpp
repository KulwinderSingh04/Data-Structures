class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long count = 0;
        long long ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 0; i < n; i++) {
            int rem = nums[i] % modulo;
            if(rem == k) count++;
            ans += m[(count - k) % modulo];
            m[count % modulo]++;
        }
        return ans;

        return 0;
    }
};