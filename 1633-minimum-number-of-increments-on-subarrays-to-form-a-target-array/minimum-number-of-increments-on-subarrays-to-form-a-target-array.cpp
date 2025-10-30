class Solution {
public:
    typedef pair<int,int> pp;
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        // vector<int> nsi(n), psi(n);
        // stack<int> st;
        // for(int i = n - 1; i >= 0; i--) {
        //     while(st.size() && target[st.top()] >= target[i]) st.pop();
        //     if(st.size()) nsi[i] = st.top();
        //     else nsi[i] = n;
        //     st.push(i);
        // }
        // stack<int> gt;
        // for(int i = 0; i < n; i++) {
        //     while(gt.size() && target[gt.top()] >= target[i]) gt.pop();
        //     if(gt.size()) psi[i] = gt.top();
        //     else psi[i] = -1;
        //     gt.push(i);
        // }
        // vector<pp> v(n);
        int ans = 0;
        int prev = 0;
        for(int i = 0; i < n; i++) {
            if(target[i] > prev) ans += target[i] - prev;
            prev = target[i];
        }
        return ans;
    }
};