class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n % 2) ans.push_back(0);
        int t = n;
        while(ans.size() != n) {
            ans.push_back(t);
            ans.push_back(-t);
            t--;
        }
        return ans;
    }
};