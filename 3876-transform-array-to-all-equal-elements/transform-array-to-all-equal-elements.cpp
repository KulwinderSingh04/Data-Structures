class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == -1) c1 += 1;
            else c2 += 1;
        }
        if(c1 % 2 == 1 && c2 % 2 == 1) return false;
        if(c1 % 2 == 0 && c2 % 2 == 0) {
            int k1 = k;
            vector<int> v1 = nums;
            for(int i = 0; i < n; i++) {
                if(v1[i] == -1) {
                    k1--;
                    v1[i] *= -1;
                    v1[i + 1] *= -1; 
                }
            }
            int k2 = k;
            vector<int> v2 = nums;
            for(int i = 0; i < n; i++) {
                if(v2[i] == 1) {
                    k2--;
                    v2[i] *= -1;
                    v2[i + 1] *= -1; 
                }
            }
            return max(k1, k2) >= 0;
        } else if(c1 % 2 == 0) {
            int k1 = k;
            for(int i = 0; i < n; i++) {
                if(nums[i] == -1) {
                    k1--;
                    nums[i] *= -1;
                    nums[i + 1] *= -1; 
                }
            }
            return k1 >= 0;
        } else {
            int k1 = k;
            for(int i = 0; i < n; i++) {
                if(nums[i] == 1) {
                    k1--;
                    nums[i] *= -1;
                    nums[i + 1] *= -1; 
                }
            }
            return k1 >= 0;
        }
        return k >= 0;
    }
};