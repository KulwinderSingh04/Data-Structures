class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        int i = 0;
        int ans = 0;
        while(m.size() != n - i) {
            m[nums[i]]--;
            if(m[nums[i]] == 0) m.erase(nums[i]);
            if(i % 3 == 0) ans++;
            i++;
        }
        return ans;
    }
};