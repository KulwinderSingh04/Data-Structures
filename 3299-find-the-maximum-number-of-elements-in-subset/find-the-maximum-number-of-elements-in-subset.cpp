class Solution {
public:
    bool isPerfectSquare(int val) {
        return (int)sqrt(val) * (int)sqrt(val) == val;
    }
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x : nums) {
            mp[x]++;
        }
        int ans = mp[1];
        if(ans % 2 == 0) ans--;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int val = nums[i];
            int a = 1;
            while(val != 1 && isPerfectSquare(val)) {
                int v = sqrt(val);
                if(mp[v] >= 2) {
                    a += 2;
                } else break;
                val = v;
            }
            ans = max(ans, a);
        }
        return ans;
    }
};