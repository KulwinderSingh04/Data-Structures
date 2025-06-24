class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        int curr = 0;
        vector<int> ans;
        while(curr < n && nums[curr] != key) curr++;
        for(int i = 0; i < n; i++) {
            if(curr == nums.size()) break;
            if(i - curr > k) {
                curr++;
                while(curr < n && nums[curr] != key) curr++;
            }
            if(curr == nums.size()) break;
            if(abs(i - curr) <= k) ans.push_back(i);
        }
        return ans;
    }
};