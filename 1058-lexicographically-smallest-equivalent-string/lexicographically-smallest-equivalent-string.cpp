class Solution {
public:
    char find(char ch, vector<char>& par) {
        if(par[ch - 97] == ch) return ch;
        return par[ch - 97] = find(par[ch - 97], par);
    }
    void Union(char ch1, char ch2, vector<char>& par) {
        char parCh1 = find(ch1, par);
        char parCh2 = find(ch2, par);
        if(parCh1 < parCh2) {
            par[parCh2 - 97] = par[parCh1- 97];
        } else if(parCh1 > parCh2) {
            par[parCh1 - 97] = par[parCh2 - 97];
        } else {
            par[parCh2 - 97] = par[parCh1 - 97];
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == s2[i]) continue;
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        vector<char> par(26), rank(26, 1);
        for(int i = 0; i < 26; i++) par[i] = i + 97;
        for(auto it : adj) {
            // cout << it.first << "-> " ;
            for(auto x : it.second) {
                // cout << x << ",";
                if(find(x, par) != find(it.first, par)) {
                    Union(x, it.first, par);
                }
            }
            // cout << endl;
        }
        string ans = "";
        for(int i = 0; i < baseStr.size(); i++) {
            ans.push_back(find(baseStr[i], par));
        }
        return ans;
    }
};