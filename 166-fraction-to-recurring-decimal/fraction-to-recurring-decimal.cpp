class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        if(num == 0) return "0";
        string ans = "";
        if(1LL * num * deno < 0) ans += '-';
        long long absNum = labs(num);
        long long absDeno = labs(deno);
        ans += to_string(absNum / absDeno);
        long long rem = absNum % absDeno;
        if(rem == 0) return ans;
        unordered_map<int, int> mp;
        ans += '.';
        while(rem != 0) {
            if(mp.find(rem) != mp.end()) {
                ans.insert(ans.begin() + mp[rem], '(');
                ans += ')';
                return ans;
            }
            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / absDeno);
            rem = rem % absDeno;
        }
        return ans;
    }
};