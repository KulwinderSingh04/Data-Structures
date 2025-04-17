class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int count = 0;
        while(i < n) {
            int j = 0;
            while(j < n) {
                if(j > i && nums[i] == nums[j]) count++;
                j += k / __gcd(k, i);
            }
            i++;
        }
        return count;
    }
};