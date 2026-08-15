class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        for(int bit = 0; bit < 32; bit++) {
            int cnt = 0;
            for(auto x : nums) {
                if((x & (1 << bit))) cnt++;
            }
            // if(cnt == 0) continue;
            if(cnt % 2) return n;
        }
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(sum == 0) return 0;
        return n - 1;
    }
};