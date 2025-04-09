class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int mn = INT_MAX;
        for(auto x : nums) {
            m[x]++;
            mn = min(mn, x);
        }
        if(k > mn) return -1;
        return m.find(k) != m.end() ? (m.size() - 1) : m.size();
    }
};