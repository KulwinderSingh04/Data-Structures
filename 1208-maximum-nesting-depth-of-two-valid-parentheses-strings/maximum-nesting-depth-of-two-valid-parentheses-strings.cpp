class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        stack<int> st;
        for(auto x : seq) {
            if(x == '(') {
                if(st.size() == 0 || st.top() == 1) {
                    ans.push_back(0);
                    st.push(0);
                } else {
                    ans.push_back(1);
                    st.push(1);
                }
            } else {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};