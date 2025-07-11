class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        int i = 0;
        int ans = 0;
        while(i < sz - 1) {
            int dis = i;
            int idx = i;
            if(i + nums[i] >= sz - 1) return ans + 1;
            for(int j = i + 1; j < min(sz, i + nums[i] + 1); j++) {
                if(j + nums[j] > dis) {
                    idx = j;
                    dis = j + nums[j]; 
                }
            }
            if(dis == i) return -1;
            i = idx;
            ans++;
        }
        return ans;
    }
};