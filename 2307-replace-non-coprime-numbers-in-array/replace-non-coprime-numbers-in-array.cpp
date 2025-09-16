class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        int a = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(__gcd(a, nums[i]) > 1) {
                a = lcm(a, nums[i]);
            } else {
                while(st.size() && __gcd(st.top(), a) > 1) {
                    a = lcm(st.top(), a);
                    st.pop();
                }
                st.push(a);
                a = nums[i];
            }
        }
        while(st.size() && __gcd(st.top(), a) > 1) {
            a = lcm(st.top(), a);
            st.pop();
        }
        st.push(a);
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};