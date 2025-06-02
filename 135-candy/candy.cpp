class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 0);
        left[0] = 1;
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                count++;
            } else count = 1;
            left[i] = count;
        }
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(i + 1 < n && ratings[i] > ratings[i + 1]) {
                count++;
            } else count = 1;
            left[i] = max(left[i], count);
            ans += left[i];
        }
        return ans;
    }
};