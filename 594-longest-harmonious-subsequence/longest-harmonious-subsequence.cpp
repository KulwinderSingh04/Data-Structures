class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        while(j < n) {
            m[nums[j]]++;
            cout << j << " ";
            while(nums[j] - nums[i] > 1) {
                m[nums[i]]--;
                if(m[nums[i]] == 0) m.erase(nums[i]);
                i++;
            }
            // cout << i << " " << j << " " << m.size() <<endl;
            if(m.size() > 1) {
                ans = max(ans, j - i + 1);
            }
            // cout << j << " ";
            j++;
        }
        return ans;
    }
};