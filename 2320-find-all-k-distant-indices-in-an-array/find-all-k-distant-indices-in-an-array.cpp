class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> v;
        int n = nums.size();
        for(int i = 0; i < n; i++) if(nums[i] == key) v.push_back(i);
        sort(v.begin(), v.end());
        int curr = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i - v[curr] > k) curr++;
            if(curr == v.size()) break;
            if(abs(i - v[curr]) <= k) ans.push_back(i);
        }
        return ans;
    }
};