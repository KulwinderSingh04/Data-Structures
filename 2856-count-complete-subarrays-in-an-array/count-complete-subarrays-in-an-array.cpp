class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++) s.insert(nums[i]);
        unordered_map<int, int> m;
        int i = 0, j = 0;
        int ans = 0;
        while(j < n) {
            m[nums[j]]++;
            while(m.size() == s.size()) {
                ans += n - j;
                m[nums[i]]--;
                if(m[nums[i]] == 0) m.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};