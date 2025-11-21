class Solution {
public:
    int fun(int x, int y, vector<vector<int>>& charSet) {
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans += (charSet[y][i] - charSet[x][i] > 0 ? 1 : 0);
        }
        return ans;
    }
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> pref(n);
        vector<int> hash(26);
        pref[0] = 1;
        hash[s[0] - 97]++;
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1];
            if(hash[s[i] - 97] == 0) pref[i] += 1;
            hash[s[i] - 97]++;
        }
        // for(auto x : pref) cout << x << " ";
        vector<int> lastPos(26, -1);
        for(int i = n - 1; i >= 0; i--) {
            if(lastPos[s[i] - 97] == -1) lastPos[s[i] - 97] = i; 
        }
        int ans = 0;
        unordered_set<int> st;
        vector<vector<int>> charSet;
        vector<int> v(26);
        for(int i = 0; i < n; i++) {
            v[s[i] - 97]++;
            charSet.push_back(v);
        }
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int pos = lastPos[ch - 97];
            if(i == pos || st.find(ch) != st.end()) continue;
            cout << i << " " << pos << endl;
            int unique = fun(i, pos - 1, charSet);
            ans += unique;
            st.insert(s[i]);
        }
        return ans;
    }
};