class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cumSum = 0;
        int leftPoints = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        long long res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == target) {
                leftPoints += mp[cumSum];
                res += leftPoints;
                cumSum++;
            }
            else {
                leftPoints -= mp[cumSum - 1];
                res += leftPoints;
                cumSum--;
            }
            mp[cumSum]++;
        }
        return res;
    }
};