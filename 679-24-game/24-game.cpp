class Solution {
public:
    bool fun(vector<double> cards) {
        int n = cards.size();
        if(n == 1) return abs(24 - cards[0]) < 0.00000001;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double a = cards[i] * cards[j];
                double b = cards[i] / cards[j];
                double c = cards[i] + cards[j];
                double d = cards[i] - cards[j];
                double e = cards[j] - cards[i];
                double f = cards[j] / cards[i];
                vector<double> newCards;
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    newCards.push_back(cards[k]);
                }
                vector<double> v = {a, b, c, d, e, f};
                for(int t = 0; t < 6; t++) {
                    if(newCards.size() == n - 2) {
                        newCards.push_back(v[t]);
                    } else {
                        newCards[n - 2] = v[t];
                    }
                    // for(auto x : newCards) cout << x << " ";
                    // cout << endl;
                    bool flag = fun(newCards);
                    if(flag) return flag;
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> newCards(4);
        for(int i = 0; i < 4; i++) newCards[i] = cards[i];
        return fun(newCards);
    }
};