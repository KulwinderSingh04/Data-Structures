class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string s = "";
        for(auto x : to_string(n)) {
            sum += x - '0';
            if(x != '0') s += x;
        }
        if(s == "") return 0;
        return stoll(s) * sum;
    }
};