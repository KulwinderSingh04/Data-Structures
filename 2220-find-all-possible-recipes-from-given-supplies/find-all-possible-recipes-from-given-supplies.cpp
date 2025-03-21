class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ing, vector<string>& supplies) {
        vector<string> ans;
        map<string, vector<string>> adj;
        int n = recipes.size();
        unordered_set<string> supply;
        for(int i = 0; i < supplies.size(); i++) supply.insert(supplies[i]);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < ing[i].size(); j++) {
                adj[ing[i][j]].push_back(recipes[i]);
            }
        }
        map<string, int> indegree;
        for(auto x : adj) {
            for(auto t : x.second) {
                indegree[t]++;
            }
        } 
        queue<string> q;
        for(auto x : adj) {
            if(indegree.find(x.first) == indegree.end()) {
                q.push(x.first);
            }
        }
        unordered_set<string> s;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(supply.find(t) == supply.end()) continue;
            s.insert(t);
            for(auto x : adj[t]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                    indegree.erase(x);
                    supply.insert(x);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(s.find(recipes[i]) != s.end()) ans.push_back(recipes[i]);
        }
        return ans;
    }
};