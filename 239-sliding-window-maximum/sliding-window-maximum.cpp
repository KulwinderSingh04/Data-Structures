class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for(int i = 0; i < n; i++) {
            while(dq.size() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            while(dq.size() && dq.front() <= i - k) dq.pop_front();
            if(i >= k - 1) ans[i - k + 1] = nums[dq.front()]; 
        }
        return ans;
    }
};