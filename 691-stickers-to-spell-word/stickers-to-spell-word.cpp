class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        int t = target.size();
        vector<int> dp((1 << t), 1e9);
        dp[0] = 0;
        for(int mask = 0; mask < (1 << t) - 1; mask++) {
            for(int i = 0; i < stickers.size(); i++) {
                vector<int> mp(26);
                int newMask = mask;
                for(auto x : stickers[i]) mp[x - 'a']++;
                for(int j = 0; j < t; j++) {
                    if((newMask & (1 << j)) == 0  && mp[target[j] - 'a'] > 0) {
                        // flag = false;
                        newMask |= (1 << j);
                        mp[target[j] - 'a']--;
                        // if(mp[target[j]] == 0) mp.erase(target[j]);
                    }
                }
                dp[newMask] = min(dp[newMask], dp[mask] + 1);
                // cout << dp[newMask] << endl;
            }
        }
        return dp[(1 << t) - 1] == 1e9 ? -1 : dp[(1 << t) - 1];
    }
};