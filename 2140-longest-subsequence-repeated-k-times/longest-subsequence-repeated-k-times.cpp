bool cmp(char& a, char& b) {
    return a > b;
}
class Solution {
public:
    bool helper(string& s, string& word, int k) {
        int n = word.size();
        int j = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(word[i] == s[j]) {
                j++;
                if(j == s.size()) {
                    count++;
                    j = 0;
                }
            }
        }
        return count >= k;
    }
    void fun(vector<int>& canUse, string& actual, string& s, string& ans, int& k, int& mxLen) {
        // int n = word.size();
        if(s.size() > mxLen) return;
        if(helper(s, actual, k)) {
            cout << s << " ";
            if(ans.size() < s.size()) {
                ans = s;
            } else if(ans.size() == s.size()) {
                if(ans < s) ans = s;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(canUse[i] != 0) {
                s.push_back(i + 'a');
                canUse[i]--;
                fun(canUse, actual, s, ans, k, mxLen);
                canUse[i]++;
                s.pop_back();
                // if(ans != "") return;
            }
        }
        
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";
        string a = "";
        unordered_map<char, int> freq;
        for(auto x : s) freq[x]++;
        vector<int> canUse(26);
        for(auto x : freq) {
            canUse[x.first - 'a'] = x.second / k;
        }
        int mxLen = s.size() / k;
        fun(canUse, s, a, ans, k, mxLen);
        return ans;
    }
};