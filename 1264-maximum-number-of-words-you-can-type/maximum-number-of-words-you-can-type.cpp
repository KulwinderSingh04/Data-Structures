class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<int> st(brokenLetters.begin(), brokenLetters.end());
        int i = 0, count = 0;
        int n = text.size();
        int a = 0;
        while(i < n) {
            if(st.find(text[i]) != st.end()) {
                count++;
                while(i < n && text[i] != ' ') i++;
            }
            if(i < n && text[i] == ' ') a++;
            i++;
        }
        return a + 1 - count;
    }
};