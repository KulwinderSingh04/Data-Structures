class Solution {
public:
    string convert(int a) {
        string s = "";
        while(a != 0) {
            s += a % 2 + 48;
            a /= 2;
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
    int revCon(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            ans += (s[i] - 48) * pow(2, n - 1 - i);
        }
        return ans;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        for(int i = 0; i < n; i++) a |= nums[i];
        string s = convert(a);
        for(int i = 0; i < n -1; i++) s += '0';
        return revCon(s);
    }
};