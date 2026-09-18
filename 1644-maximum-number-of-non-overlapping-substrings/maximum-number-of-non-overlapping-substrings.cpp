class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        for(int i = n - 1; i >= 0; i--) {
            first[s[i] - 'a'] = i;
        }
        vector<vector<int>> vec;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            int i = first[ch - 'a'];
            int j = last[ch - 'a'];
            if(i == -1) continue;
            int pi = i;
            int pj = j;
            while(true) {
                int ci = i, cj = j;
                for(int k = i + 1; k < j; k++) {
                    ci = min(ci, first[s[k] - 'a']);
                    cj = max(cj, last[s[k] - 'a']);
                }
                if(ci == i && cj == j) break;
                i = ci;
                j = cj;
                // cout << i << " " << j << "ee" << endl;
            }
            vec.push_back({i, j});
        }
        for(auto x : vec) {
            cout << x[0] << " " << x[1] << endl;
        }
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        vector<int> hash(n + 1);
        vector<string> ans;
        for(auto x : vec) {
            int i = x[0];
            int j = x[1];
            string str = "";
            int flag = 1;
            for(int k = i; k <= j; k++) {
                str += s[k];
                if(hash[k] == 1) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0) continue;
            // cout << i << " " << j << " " << str << endl;
            ans.push_back(str);
            for(int k = i; k <= j; k++) {
                hash[k] = 1;
            }
        }
        return ans;
    }
};