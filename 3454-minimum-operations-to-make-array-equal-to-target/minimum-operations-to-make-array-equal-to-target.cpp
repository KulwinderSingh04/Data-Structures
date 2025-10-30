class Solution {
public:
    long long fun(vector<int>& target, int lo, int hi) {
        long long ans = 0;
        int prev = 0;
        for(int i = lo; i <= hi; i++) {
            if(abs(target[i]) > abs(prev)) ans += abs(target[i]) - abs(prev);
            prev = target[i];
        }
        return ans;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diff(n);
        for(int i = 0; i < n; i++) {
            diff[i] = target[i] - nums[i];
        }
        int prevIdx = 0;
        long long ans = 0;
        for(int i = 1; i < n; i++) {
            if((diff[prevIdx] <= 0 && diff[i] >= 0) || (diff[prevIdx] >= 0 && diff[i] <= 0)) {
                ans += fun(diff, prevIdx, i - 1);
                prevIdx = i;
            }
            
        }
        ans += fun(diff, prevIdx, n - 1);
        return ans;
    }
};