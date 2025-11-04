class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for(int i = 0; i < n - k + 1; i++) {
            priority_queue<pair<int, int>> pq;
            unordered_map<int, int> mp;
            for(int j = i; j < i + k; j++) mp[nums[j]]++;
            for(auto x : mp) pq.push({x.second, x.first});
            int t = x;
            while(pq.size() && t--) {
                auto ele = pq.top();
                pq.pop();
                ans[i] += ele.first * ele.second;
            }
        }
        return ans;
    }
};