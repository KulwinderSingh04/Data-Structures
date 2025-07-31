class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> prev, curr, res;
        for(int i = 0; i < n; i++) {
            for(auto x : prev) {
                curr.insert(x | arr[i]);
                res.insert(x | arr[i]);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return res.size();
    }
};