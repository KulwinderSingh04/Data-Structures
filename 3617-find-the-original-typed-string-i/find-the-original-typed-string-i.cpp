class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        int ans = 0;
        int n = word.size();
        for(int i = 1; i < n; i++) {
            if(word[i] == word[i - 1]) {
                count++;
            } else {
                ans += count - 1;
                count = 1;
            }
        }
        ans += count;
        return ans;
    }
};