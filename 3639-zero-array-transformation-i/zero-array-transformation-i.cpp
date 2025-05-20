class Solution {
public:
    vector<int> processQuery(int n, vector<vector<int>>& queries) {
        
        vector<int> zeroArray(n);
        for(int i = 0; i < queries.size(); i++) {
            zeroArray[queries[i][0]] += 1;
            if(queries[i][1] + 1 < n) zeroArray[queries[i][1] + 1] -= 1;
        }
        for(int i = 1; i < n; i++) {
            zeroArray[i] += zeroArray[i - 1];
        }
        return zeroArray;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> v = processQuery(n, queries);
        for(int i = 0; i < n; i++) {
            if(nums[i] - v[i] > 0) return false;
        }
        return true;
    }
};