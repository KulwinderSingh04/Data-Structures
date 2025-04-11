class Solution {
public:
    bool fun(string& s) {
        int n = s.size();
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) {
            if(i < n / 2) sum1 += s[i] - '0';
            else sum2 += s[i] - '0';
        }
        return sum1 == sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++) {
            string s = to_string(i);
            if(s.size() % 2 == 0) {
                if(fun(s)) count++;
            }
        }
        return count;
    }
};