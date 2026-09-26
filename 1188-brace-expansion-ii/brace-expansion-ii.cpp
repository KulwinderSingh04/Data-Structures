class Solution {
public:
    int idx = 0;
    string s;
    int n;
    set<string> getUnit() {
        set<string> res;
        if(s[idx] == '{') {
            idx++;
            res = performUnion();
        } else {
            res = {string(1, s[idx])};
        }
        idx++;
        return res;
    }
    set<string> performConcat() {
        set<string> res = {""};
        while(idx < n && (s[idx] == '{' || isalpha(s[idx]))) {
            set<string> temp = getUnit();
            set<string> resNew;
            for(const auto& l : res) {
                for(const auto& r : temp) {
                    resNew.insert(l + r);
                }
            }
            res = resNew;
        }
        return res;
    }
    set<string> performUnion() {
        set<string> res;
        while(true) {
            set<string> temp = performConcat();
            res.insert(temp.begin(), temp.end());
            if(idx < n && s[idx] == ',') idx++;
            else break;
        }
        return res;
    }
    vector<string> braceExpansionII(string exp) {
        n = exp.size();
        s = exp;
        set<string> st = performUnion();
        vector<string> res;
        for(auto x : st) res.push_back(x);
        return res; 
    }
};