class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0;
        int j = n - 1;
        int ans = 0, count = 0;
        while(i <= j) {
            if(power >= tokens[i]) {
                count++;
                ans = max(ans, count);
                power -= tokens[i];
                i++;
            } else {
                if(count > 0) {
                    power += tokens[j];
                    j--;
                    count--;
                } else return ans;
            }
        }
        return ans;
    }
};