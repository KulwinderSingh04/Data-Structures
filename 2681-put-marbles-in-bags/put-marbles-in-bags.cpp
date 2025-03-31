class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> div;
        for(int i = 0; i < n - 1; i++) {
            div.push_back(weights[i] + weights[i + 1]);
        }
        sort(div.begin(), div.end());
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i = 0; i < k - 1; i++) {
            sum1 += div[i];
            sum2 += div[div.size() - 1 - i];
        }
        return sum2 - sum1;
    }
};