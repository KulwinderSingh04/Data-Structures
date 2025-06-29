class Solution {
public:
    int binSearch(vector<int>& nums, int target) {
        int lo = 0;
        int n = nums.size();
        int hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target && (mid == n - 1 || nums[mid] != nums[mid + 1])) return mid;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return hi;
    }
    int MOD = 1e9 + 7;
    long long pow(int a, int b) {
        if(b == 0) return 1;
        long long half = pow(a, b / 2) % MOD;
        half = (half * half) % MOD;
        if(b % 2) return (half * a) % MOD;
        return half;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int idx = binSearch(nums, target - nums[i]);
            cout << idx << " ";
            if(idx - i >= 0) {
                ans = (ans + pow(2, idx - i)) % MOD;
            }
        }
        return ans;
    }
};