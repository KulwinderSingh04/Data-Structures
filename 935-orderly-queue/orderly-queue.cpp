class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            int n = s.size();
            string ans = "";
            while(n--) {
                char ch = s[0];
                s.erase(s.begin());
                s.push_back(ch);
                if(ans == "" || ans > s) ans = s;
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};