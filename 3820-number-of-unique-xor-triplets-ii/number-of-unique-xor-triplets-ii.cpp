class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        vector<bool> poss(3001, false);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                poss[nums[i] ^ nums[j]] = true;
            }
        }
        int count = 0;
        for(int i = 0; i < 3001; i++) {
            for(int j = 0; j < n; j++) {
                if(((i ^ nums[j]) <= 3000) && poss[i ^ nums[j]]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};