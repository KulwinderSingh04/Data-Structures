class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int sz = s.size();
        return (s[sz - 2] - 48) * (s[sz- 1] - 48);
    }
};