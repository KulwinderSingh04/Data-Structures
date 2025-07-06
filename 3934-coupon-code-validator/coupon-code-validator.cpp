class Solution {
public:
    bool alpha(string& s) {
        if(s == "") return false;
        for(auto x : s) {
            // cout << (int)x << " ";
            if((x < 'a' || x > 'z') && (x < 'A' || x > 'Z') && (x < '0' || x > '9') && x != '_') return false;
        }
        return true;
    }
    bool check(string& s) {
        return s == "restaurant" || s == "grocery" || s == "pharmacy" || s == "electronics";
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> ans;
        int n = code.size();
        for(int i = 0; i < n; i++) {
            if(alpha(code[i]) && check(businessLine[i]) && isActive[i]) ans.push_back({businessLine[i], code[i]});
        }
        sort(ans.begin(), ans.end());
        vector<string> res;
        for(auto x : ans) res.push_back(x.second);
        return res;
    }
};