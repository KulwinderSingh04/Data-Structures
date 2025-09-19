class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<vector<int>> st(roads.begin(), roads.end());
        unordered_map<int, int> degree;
        for(auto x : roads) {
            degree[x[0]]++;
            degree[x[1]]++;
        }
        vector<pair<int, int>> a;
        for(auto x : degree) a.push_back(x);
        sort(a.begin(), a.end(), [](pair<int, int>& x, pair<int, int>& y) {
            return x.second > y.second;
        });
        // for(int i = 0; i < a.size(); i++) cout << a[i].first << " " << a[i].second << endl;
        if(a.size() == 0) return 0;
        int ans = 0;
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < a.size(); j++) {
                if(i == j) continue;
                int x = a[i].second + a[j].second;
                if(st.find({a[i].first, a[j].first}) != st.end() || st.find({a[j].first, a[i].first}) != st.end()) x--;
                if(x >= ans) ans = x;
                else break;
            }
        }
        return ans;

    }
};