class Solution {
public:
    bool isVowel(int x) {
        return x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        int q = queries.size();
        vector<string> ans(q);
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        unordered_map<string, string> mp1, mp2;
        for(auto x : wordlist) {
            string a = x;
            for(int i = 0; i < a.size(); i++) {
                if(a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
            }
            if(mp1.find(a) == mp1.end()) mp1[a] = x;
            for(auto& y : a) if(isVowel(y)) y = '1';
            if(mp2.find(a) == mp2.end()) mp2[a] = x;
        }
        for(int i = 0; i < q; i++) {
            string a = queries[i];
            if(st.find(a) != st.end()) ans[i] = a;
            else {
                for(auto& x : a) if(x >= 'A' && x <= 'Z') x += 32;
                if(mp1.find(a) != mp1.end()) {
                    ans[i] = mp1[a];
                } else {
                    for(auto& x : a) if(isVowel(x)) x = '1';
                    if(mp2.find(a) != mp2.end()) ans[i] = mp2[a];
                }
            }
        }
        return ans;
    }
};