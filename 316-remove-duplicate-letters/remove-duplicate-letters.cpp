class Solution {
public:
    bool check(int a, int mask) {
        for(int i = 0; i < 32; i++) {
            if((mask & (1 << i)) == 0) continue;
            if((a & (1 << i)) == 0) return false;
        }
        return true;
    }
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans = "";
        int idx = -1;
        vector<int> suff(n);
        unordered_map<int, int> mp;
        int mask = 0;
        for(int i = n - 1; i >= 0; i--) {
            suff[i] = mask;
            if(mp[s[i]] == 0) mask |= (1 << (s[i] - 'a'));
            mp[s[i]]++;
        }
        int sz = mp.size();
        for(int i = 0; i < sz; i++) {
            char x = '_';
            for(char ch = 'a'; ch <= 'z'; ch++) {
                if((mask & (1 << (ch - 'a'))) == 0) continue;
                bool flag = false;
                for(int j = idx + 1; j < n; j++) {
                    
                    if(s[j] == ch) {
                        int bitMask = mask;
                        bitMask = (bitMask ^ (1 << (ch - 'a')));
                        if(check(suff[j], bitMask)) {
                            idx = j;
                            flag = true;
                        } else flag = false;
                        break;
                    }
                }
                if(flag == true) {
                    x = ch;
                    break;
                }
            }
            mask = (mask ^ (1 << (x - 'a')));
            ans += x;
        }
        return ans;
    }
};