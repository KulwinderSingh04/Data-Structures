class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ngi(n);
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() && nums[st.top()] < nums[i]) st.pop();
            if(st.size()) ngi[i] = st.top();
            else ngi[i] = n;
            st.push(i);
        }
        int i = 0;
        int a = 0;
        while(i < n) {
            a += ngi[i] - i - 1;
            i = ngi[i];
        }
        return n - a;
    }
};