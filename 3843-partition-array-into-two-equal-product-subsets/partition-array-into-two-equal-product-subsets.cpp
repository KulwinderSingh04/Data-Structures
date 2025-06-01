class Solution {
public:
    bool fun(int i, vector<int>& nums, long long target, vector<int>& v) {
        int n = nums.size();
        if(i == n) {
            unsigned long long pr1 = 1, pr2 = 1;
            for(int i = 0; i < n; i++) {
                if(v[i]) pr1 *= nums[i];
                else pr2 *= nums[i];
            }
            if(pr1 == target && pr1 == pr2) return true;
            return false;
        }

        v[i] = 1;
        bool a = fun(i + 1, nums, target, v);
        v[i] = 0;
        
        bool b = fun(i + 1, nums, target, v);
        return a || b;

    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        vector<int> v(n);
        return fun(0, nums, target, v);
    }
};