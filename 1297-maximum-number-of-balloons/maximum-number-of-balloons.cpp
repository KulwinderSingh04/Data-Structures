class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int, int> mp;
        for(auto x : text) {
            mp[x]++;
        }
        int mn = mp['l'] / 2;
        mn = min(mn, mp['b']);
        mn = min(mn, mp['a']);
        mn = min(mn, mp['n']);
        mn = min(mn, mp['o'] / 2);
        return mn;
    }
};