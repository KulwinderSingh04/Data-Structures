class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int xo = 0;
        if(nums.size() % 2 == 1) return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            xo ^= nums[i];
            if(i % 2 == 1) if(xo != 0) return false;
        }
        return true;
    }
};