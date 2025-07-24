class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();
        vector<int> lis;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int idx = upper_bound(lis.begin(), lis.end(), obs[i]) - lis.begin();
            res.push_back(idx + 1);
            if(idx == lis.size()) lis.push_back(obs[i]);
            else lis[idx] = obs[i];
        }
        return res;
    }
};