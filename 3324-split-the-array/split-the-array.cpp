class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(auto x : nums) m[x]++;
        for(auto x : m) {
            if(x.second > 2) return false;
        }
        return true;
    }
};