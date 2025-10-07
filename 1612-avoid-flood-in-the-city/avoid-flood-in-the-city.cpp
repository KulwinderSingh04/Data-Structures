class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> mp;
        int n = rains.size();
        set<int> st;
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++) {
            if(rains[i] != 0) {
                if(mp.find(rains[i]) != mp.end()) {
                    auto it = st.lower_bound(mp[rains[i]]);
                    if(it == st.end()) return {};
                    ans[*it] = rains[i];
                    st.erase(*it);
                } 
                mp[rains[i]] = i;
                ans[i] = -1;
            } else {
                st.insert(i);
            }
        }
        return ans;
    }
};