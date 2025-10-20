class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for(auto x : edges) indegree[x[1]]++;
        int idx = -1, count = 0;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                count++;
                idx = i;
            }
        }
        if(count == 1) return idx;
        return -1;
    }
};