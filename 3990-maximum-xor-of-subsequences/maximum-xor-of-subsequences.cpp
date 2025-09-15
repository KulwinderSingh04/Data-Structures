class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> basis(32);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            for(int j = 31; j >= 0; j--) {
                if((num & (1 << j)) == 0) continue;
                if(basis[j] == 0) {
                    basis[j] = num;
                    break;
                } else {
                    num ^= basis[j];
                }
            } 
        }
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            ans = max(ans, ans ^ basis[i]);
        }
        return ans;
    }
};