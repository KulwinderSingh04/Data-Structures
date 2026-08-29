class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        vector<int> v1;
        for(int i = 0; i < n; i++) {
            v1.push_back(vec[i][1]);
        }
        int prev = 0;
        for(int i = 1; i < n; i++) {
            if(vec[i][0] - vec[i - 1][0] > limit) {
                sort(v1.begin() + prev, v1.begin() + i);
                prev = i;
            } 
        }
        sort(v1.begin() + prev, v1.end());
        for(int i = 0; i < n; i++) {
            nums[v1[i]] = vec[i][0];
        }
        return nums;
    }
};