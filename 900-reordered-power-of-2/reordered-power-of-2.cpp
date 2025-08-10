class Solution {
public:
    void fun(unordered_set<string>& s) {
        long long a = 1;
        while(a <= 1e9) {
            string str = to_string(a);
            sort(str.begin(), str.end());
            s.insert(str);
            a *= 2;
        }
    }
    bool reorderedPowerOf2(int n) {
        unordered_set<string> s;
        fun(s);
        string str = to_string(n);
        sort(str.begin(), str.end());
        return s.find(str) != s.end();
    }
};