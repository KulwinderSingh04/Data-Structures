class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value);
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int rem = nums[i] % value;
            if(rem < 0) rem += value;
            st.insert(mp[rem] + rem);
            mp[rem] += value;
        }
        int x = 0;
        while(st.find(x) != st.end()) {
            x++;
        }
        return x;
    }
};