class Solution {
public:
    bool fun(int a, int b, vector<unordered_set<int>>& lang) {
        for(auto x : lang[a]) {
            if(lang[b].find(x) != lang[b].end()) {
                return true;
            }
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> st;
        vector<unordered_set<int>> lang(languages.size() + 1);
        for(int i = 0; i < languages.size(); i++) {
            for(int j = 0; j < languages[i].size(); j++) {
                lang[i + 1].insert(languages[i][j]);
            }
        }
        for(auto f : friendships) {
            if(!fun(f[0], f[1], lang)) {
                st.insert(f[0]);
                st.insert(f[1]);
            }
        }
        vector<int> count(n + 1);
        for(auto x : st) {
            for(auto y : lang[x]) {
                count[y]++;
            }
        }
        int idx = 0;
        for(int i = 1; i <= n; i++) {
            if(count[idx] < count[i]) idx = i;
        }
        return st.size() - count[idx];
    }
};