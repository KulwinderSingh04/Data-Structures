class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        int ans = -1;
        for(auto x : arr) m[x]++;
        for(auto x : m) if(x.second == x.first && x.first > ans) ans = x.second;
        return ans;
    }
};