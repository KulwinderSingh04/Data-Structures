class Solution {
public:
    int fun(int i, int dir, vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        int j = i;
        while(j >= 0 && j < n) {
            if(v[j] != 0) {
                v[j]--;
                dir = (dir == -1 ? 1 : -1);
            }
            j += dir;
        }
        for(auto x : v) {
            if(x != 0) {
                return 0;
            }
        }
        return 1;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                if(fun(i, 1, nums) == 1) {
                    // cout << i << " " << 1 << endl;
                    count++;
                } 
                if(fun(i, -1, nums) == 1) {
                    // cout << i << " " << -1 << endl;
                    count++;
                }
            }
        }
        return count;
    }
};