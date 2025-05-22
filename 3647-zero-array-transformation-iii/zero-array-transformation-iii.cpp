class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        priority_queue<int> mxHeap;
        priority_queue<int, vector<int>, greater<int>> mnHeap;
        sort(queries.begin(), queries.end());
        int j = 0;
        int usedCount = 0;
        for(int i = 0; i < n; i++) {
            while(j < queries.size() && queries[j][0] == i) {
                mxHeap.push(queries[j][1]);
                j++;
            }
            nums[i] -= mnHeap.size();
            if(nums[i] > 0) {
                while(mxHeap.size() && nums[i] > 0 && mxHeap.top() >= i) {
                    nums[i]--;
                    usedCount++;
                    mnHeap.push(mxHeap.top());
                    mxHeap.pop();
                }
                if(nums[i] > 0) return -1;
            } 
            while(mnHeap.size() && mnHeap.top() <= i) mnHeap.pop();
        }
        return queries.size() - usedCount;
    }
};