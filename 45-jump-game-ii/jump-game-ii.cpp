class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int i = 0;
        int l = 0;
        int r = 0;
        int count = 0;
        while(r < n - 1) {
            int f = 0;
            for(int j = l; j <= r; j++) {
                f = max(f, j + nums[j]);
            }
            l = r + 1;
            r = f;
            count++;
        }
        return count;
    }
};