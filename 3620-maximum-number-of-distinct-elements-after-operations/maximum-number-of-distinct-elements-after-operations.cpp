class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[0] - k;
        int ans = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            if(a > nums[i] + k) continue;
            if(a >= nums[i] - k) {
                if(st.end(a) == st.end()) {
                    ans++;
                    st.insert(a);
                }
                a++;
            } else {
                a = nums[i] - k;
                if(st.find(a) == st.end()) {
                    ans++;
                    st.insert(a);
                }
                a++;
            }
        }
        return ans;

    }
};