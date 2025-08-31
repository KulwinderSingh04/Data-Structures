class Solution {
public:
    int score(vector<string>& cards, char x) {
        int c1 = 0, c2 = 0, c0 = 0;
        unordered_map<char, int> a, b;
        for(auto card : cards) {
            if(card[0] == x && card[1] == x) c0++;
            else if(card[0] == x) {
                c1++;
                a[card[1]]++;
            }
            else if(card[1] == x) {
                c2++;
                b[card[0]]++;
            }
        }
        int mx1 = 0, mx2 = 0;
        for(auto x : a) mx1 = max(x.second, mx1);
        for(auto x : b) mx2 = max(x.second, mx2);
        int l = min(c1 / 2, c1 - mx1);
        int y = min(c2 / 2, c2 - mx2);
        int leftc1 = c1 - 2 * l;
        int leftc2 = c2 - 2 * y;
        int tot = leftc1 + leftc2;;
        int ans = l + y + min(c0, tot);
        c0 -= min(c0, tot);
        ans += min((l + y) / 2, c0 / 2);
        return ans;
    }
};