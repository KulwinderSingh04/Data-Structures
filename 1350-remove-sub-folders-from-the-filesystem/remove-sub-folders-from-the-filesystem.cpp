class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        unordered_set<string> st;
        sort(folder.begin(), folder.end());
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < folder[i].size(); j++) {
                string sub = folder[i].substr(0, j + 1);
                if(st.find(sub) != st.end() && (j + 1 >= folder[i].size() || folder[i][j + 1] == '/')) {
                    flag = true;
                    break;
                }
            }
            if(!flag) st.insert(folder[i]);
        }
        vector<string> ans;
        for(auto x : st) ans.push_back(x);
        return ans;
    }
};