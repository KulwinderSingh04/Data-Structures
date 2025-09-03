class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(i);
        }
        vector<int> ans;
        for(auto x : queries) {
            int u = x[0];
            int v = x[1];
            if(st.find(u) == st.end() || st.find(v) == st.end()) {
                ans.push_back(st.size() - 1);
                continue;
            }

            auto it = st.find(u);
            it++;
            while(*it < v) {
                auto temp = it;
                temp++;
                st.erase(*it);
                it = temp;
            }
            ans.push_back(st.size() - 1);
        }
        return ans;
    }
};