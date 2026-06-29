class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto x : patterns) {
            for(int i = 0; i < word.size(); i++) {
                if(word.substr(i, x.size()) == x) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};