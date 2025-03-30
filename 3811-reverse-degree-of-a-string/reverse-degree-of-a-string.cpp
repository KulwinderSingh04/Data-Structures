class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            sum += ('z' - s[i] + 1) * (i + 1);
        }
        return sum;
    }
};