class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, set<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].insert(i);
        }
        stack<int> st;
        vector<int> nsi(n);
        for(int i = n - 1; i>= 0; i--) {
            while(st.size() && nums[st.top()] >= nums[i]) st.pop();
            if(st.size()) nsi[i] = st.top();
            else nsi[i] = n;
            st.push(i);
        }
        // for(int i = 0; i < n; i++) cout << nsi[i] << " ";
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;
            int idx = nsi[i];
            for(auto x : mp[nums[i]]) {
                if(x >= idx) break;
                nums[x] = 0;
                mp[nums[i]].erase(x);
            }
            ans++;
        }
        return ans;
    }
};