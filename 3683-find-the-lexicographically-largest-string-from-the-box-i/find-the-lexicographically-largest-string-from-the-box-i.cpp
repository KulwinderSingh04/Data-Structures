class Solution {
public:
    bool fun(string word, int s1, int e1, int s2, int e2) {
        while(s1 <= e1) {
            if(word[s1] < word[s2]) return true;
            if(word[s1] > word[s2]) return false;
            s1++;
            s2++;
        }
        return true;
    }
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;
        int mxLen = n - numFriends + 1;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(fun(word, idx, min(mxLen + idx, n - 1), i, min(n - 1, mxLen + i))) {
                idx = i;
            }
        }
        return word.substr(idx, min(mxLen, n - 1));
    }
};