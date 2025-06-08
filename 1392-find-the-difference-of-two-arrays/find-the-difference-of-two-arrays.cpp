class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_set<int> s1, s2;
        for(auto x : nums1) s1.insert(x);
        for(auto x : nums2) s2.insert(x);
        vector<vector<int>> ans(2);
        for(int i = 0; i < n1; i++) {
            if(s2.find(nums1[i]) == s2.end()) {
                ans[0].push_back(nums1[i]);
            }
            s2.insert(nums1[i]);
        }
        for(int i = 0; i < n2; i++) {
            if(s1.find(nums2[i]) == s1.end()) ans[1].push_back(nums2[i]);
            s1.insert(nums2[i]);
        }
        return ans;
    }
};