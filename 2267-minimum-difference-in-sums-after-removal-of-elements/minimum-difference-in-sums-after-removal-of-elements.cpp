class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int n3 = n / 3;
        vector<long long> left(n), right(n);
        long long sum = 0;
        priority_queue<long long> pqMax;
        priority_queue<long long, vector<long long>, greater<long long>> pqMin;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            // cout << sum << " ";
            pqMax.push(nums[i]);
            if(i >= n3) {
                sum -= pqMax.top();
                pqMax.pop();
            }
            // cout << sum << " ";
            left[i] = sum;
        }
        sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            if(i < n - n3) {
                sum -= pqMin.top();
                pqMin.pop();
            }
            pqMin.push(nums[i]);
            right[i] = sum;
        }
        long long ans = LLONG_MAX;
        for(int i = n3 - 1; i < n - n3; i++) {
            ans = min(ans, left[i] - right[i + 1]);
        }
        return ans;
    }
};