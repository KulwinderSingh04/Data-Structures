class Solution {
public:
    bool ham(string a, string b) {
        if(a.size() != b.size()) return false;
        int n = a.size();
        int ham = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) ham++;
            if(ham > 1) return false;
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        int n = words.size();
        vector<int> par(n);
        for(int i = 0; i < n; i++) par[i] = i;

        vector<int> dp(n, 1);
        int idx = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(ham(words[i], words[j]) && groups[i] != groups[j]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        par[i] = j;
                    }
                }
            }
            if(idx == -1 || dp[idx] < dp[i]) {
                idx = i;
            }
        }
        // cout << idx << endl;
        // for(int i = 0 ; i < n; i++) cout << par[i] << " ";
        vector<string> ans;
        while(idx != par[idx]) {
            ans.push_back(words[idx]);
            idx = par[idx];
        }
        ans.push_back(words[idx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};