class Solution {
public:
    typedef pair<int, int> pp;
    bool dfs(int ci, int cj, vector<int>& remCount, vector<vector<int>>& isDone, vector<vector<int>>& a, vector<vector<int>>& ans) {
        int n = isDone.size();
        if(a.size() == n * (n - 1)) {
            ans = a;
            return true;
        }
        vector<pp> v;
        for(int i = 0; i < remCount.size(); i++) {
            if(i == ci || i == cj) continue;
            if(remCount[i] != 0) {
                v.push_back({remCount[i], i});
            }
        }
        sort(v.begin(), v.end(), greater<pp> ());
        // while(v.back().first != v[0].first) v.pop_back();
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                if(i == j || isDone[v[i].second][v[j].second] == 1) continue;
                remCount[v[i].second]--;
                remCount[v[j].second]--;
                isDone[v[i].second][v[j].second] = 1;
                a.push_back({v[i].second, v[j].second});
                bool f = dfs(v[i].second, v[j].second, remCount, isDone, a, ans);
                if(f) return f;
                a.pop_back();
                isDone[v[i].second][v[j].second] = 0;
                remCount[v[j].second]++;
                remCount[v[i].second]++;
            }
        }
        return false;
    }
    vector<vector<int>> generateSchedule(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    vector<vector<int>> a;
                    a.push_back({i, j});
                    vector<int> remCount(n, 2 * (n - 1));
                    remCount[i]--;
                    remCount[j]--;
                    vector<vector<int>> isDone(n, vector<int> (n));
                    isDone[i][j] = 1;
                    dfs(i, j, remCount, isDone, a, ans);
                    if(ans.size() != 0) return ans;
                }
            }
        }
        return ans;
    }
};