class Solution {
public:
    bool helper(string& str, vector<int>& st) {
        for(int i = 0; i < str.size(); i++) if(st[str[i] - 97] == 1) return false;
        return true;
    }
    bool helper2(string& str) {
        sort(str.begin(), str.end());
        for(int i = 0; i < str.size() - 1; i++) if(str[i] == str[i + 1]) return false;
        return true;
    }
    int fun(int i, vector<string>& arr, vector<int>& st) {
        int n = arr.size();
        if(i == n) return 0;
        int p = 0;
        if(helper2(arr[i]) && helper(arr[i], st)) {
            for(int j = 0; j < arr[i].size(); j++) st[arr[i][j] - 97] = 1;
            p = arr[i].size() + fun(i + 1, arr, st);
            for(int j = 0; j < arr[i].size(); j++) st[arr[i][j] - 97] = 0;
        }

        int np = fun(i + 1, arr, st);
        return max(np, p);
    }
    int maxLength(vector<string>& arr) {
        vector<int> st(26);
        return fun(0, arr, st);
    }
};