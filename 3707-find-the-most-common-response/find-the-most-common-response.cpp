class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();
        unordered_map<string, int> m;
        for(int i = 0; i < n; i++) {
            sort(responses[i].begin(), responses[i].end());
            m[responses[i][0]]++;
            for(int j = 1; j < responses[i].size(); j++) {
                if(responses[i][j] != responses[i][j - 1]) m[responses[i][j]]++;
            }
        }
        string ans = "";
        int mx = -1;
        for(auto x : m) {
            string str = x.first;
            int freq = x.second;
            if(freq >= mx) {
                if(freq == mx) {
                    if(ans != "") ans = min(str, ans);
                    else ans = str;
                } else {
                    ans = str;
                }
                mx = freq;
            }
        }
        return ans;
    }
};