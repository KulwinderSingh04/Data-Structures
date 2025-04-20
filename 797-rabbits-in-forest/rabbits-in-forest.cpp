class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        int n = answers.size();
        for(int i = 0; i < n; i++) m[answers[i]]++;
        int ans = 0;
        for(auto x : m) {
            int a = x.second / (x.first + 1);
            if(x.second % (x.first + 1) != 0) a++;
            a *= (x.first + 1);
            ans += a;
        }
        return ans;
    }
};