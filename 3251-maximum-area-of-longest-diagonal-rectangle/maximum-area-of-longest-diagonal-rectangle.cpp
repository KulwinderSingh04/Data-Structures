class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        double mx = 0;
        for(auto x : dimensions) {
            double dia = sqrt(x[0] * x[0] + x[1] * x[1]);
            if(mx == dia) ans = max(ans, x[0] * x[1]);
            else if(mx < dia) {
                mx = dia;
                ans = x[0] * x[1];
            }
        }
        return ans;
    }
};