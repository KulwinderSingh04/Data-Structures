class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // vector<int> v;
        int n = nums.size();
        // for(int i = 0; i < n; i++) if(nums[i] == key) v.push_back(i);
        // sort(v.begin(), v.end());
        int curr = 0;
        // while(curr < n && nums[curr] != key) curr++;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            while(curr < n && nums[curr] != key) curr++;
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