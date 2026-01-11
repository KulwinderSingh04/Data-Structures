class Solution {
public:
    long long countPairs(vector<string>& s) {
        int n = s.size();
        unordered_map<string, int> mp;
        // int n = words.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            string num = "";
            
            for(int j = 1; j < s[i].size(); j++) {
                int t = s[i][j] - s[i][j - 1];
                num += to_string(t < 0 ? t + 26 : t) + '_';
            }
            // cout << num << " ";
            ans += mp[num];
            mp[num]++;
        }
        return ans;
    }
};