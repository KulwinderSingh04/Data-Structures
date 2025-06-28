bool cmp(int& a, int& b) {
    return a > b;
}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v = nums;
        int n = nums.size();
        sort(v.begin(), v.end(), cmp);
        unordered_map<int, int> m;
        for(int i = 0; i < k; i++) m[v[i]]++;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(m[nums[i]]) {
                ans.push_back(nums[i]);
                m[nums[i]]--;
            }
        }

        return ans;
    }
};