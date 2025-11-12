class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int a = 1e7;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) count++;
            int g = 0;
            for(int j = i; j < n; j++) {
                g = __gcd(g, nums[j]);
                if(g == 1) a = min(a, j - i + 1);
            }
        }
        if(count != 0) return n - count;
        if(a == 1e7) return -1;
        return a - 1 + n - 1;

    }
};