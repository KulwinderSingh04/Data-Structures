class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int n = bank.size();
        int m = bank[0].size();
        int ans = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // if(i == j) continue;?
                count += bank[i][j] == '1';
            }
            ans += prev * count;
            if(count != 0) prev = count;
            count = 0;
        }
        return ans;
    }
};