class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n2 = t.size();
        int n1 = s.size();
        if(n2 < n1) return false;
        if(n1 == 1) return true;
        vector<int> pref(n1, -1), suff(n1, -1);
        int i = 0;
        for(int j = 0; j < n2; j++) {
            if(s[i] == t[j]) {
                pref[i] = j;
                i++;
            }
            if(i == n1) break;
        }
        if(i == n1) return true;
        i = n1 - 1;
        for(int j = n2 - 1; j >= 0; j--) {
            if(s[i] == t[j]) {
                suff[i] = j;
                i--;
            }
            if(i == -1) break; 
        }
        // for(auto x : pref) cout << x << endl;
        for(int j = 0; j < n1; j++) {
            if(j == 0) {
                if(suff[j + 1] > 0) return true;
            } else if(j == n1 - 1) {
                // if(s[j] == 's') cout << pref[j - 1] << endl;
                if(pref[j - 1] != -1 && pref[j - 1] < n2 - 1) return true;
            } else {
                if(pref[j - 1] != -1 && suff[j + 1] - pref[j - 1] > 1) return true;
            }
        }
        return false;
        
    }
};