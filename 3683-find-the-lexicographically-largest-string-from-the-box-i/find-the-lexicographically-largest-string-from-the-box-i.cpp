class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;
        int i = 0;
        int j = 1;
        int mxLen = n - numFriends + 1;
        while(j < n) {
            if(word[i] < word[j]) {
                i = j;
                j++;
            } else if(word[i] > word[j]) {
                j++;
            } else {
                int k = 1;
                while(j + k < n && word[i + k] == word[j + k]) {
                    k++;
                }
                if(word[i + k] < word[j + k]) i = j;
                j++;
            }
        }
        return word.substr(i, mxLen);
    }
};