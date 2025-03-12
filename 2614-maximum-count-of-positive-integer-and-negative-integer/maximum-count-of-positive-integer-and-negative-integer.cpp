class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int zero = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == 0 && (mid <= 0 || nums[mid - 1] < 0)) {
                zero = mid;
                break;
            }
            else if(nums[mid] >= 0) hi = mid - 1;
            else lo = mid + 1;
        }
        if(zero == -1) {
            return max(hi + 1, n - hi - 1);
        }
        lo = zero;
        hi = n - 1;
        int hero = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == 0 && (mid >= n - 1 || nums[mid + 1] > 0)) {
                hero = mid;
                break;
            }
            else if(nums[mid] > 0) hi = mid - 1;
            else lo = mid + 1;
        }
        cout << zero << " " << hero << endl;
        return max(zero, n - hero - 1);
    }
};