class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum = 1LL * n * (n + 1) / 2;
        if(abs(target) > sum) return {};
        if((sum - target) % 2 != 0) return {};
        long long t = (sum - target);
        long long num = n;
        unordered_set<int> st;
        vector<int> ans;
        while(t) {
            long long mn = min(2 * num, t);
            st.insert(mn / 2);
            ans.push_back(-mn / 2);
            t -= mn;
            num--;
        }
        for(int i = 1; i <= n; i++) {
            if(st.find(i) == st.end()) ans.push_back(i);
        }
        return ans;
        
    }
};