class Solution {
public:
    bool fun(long long mid, vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        long long count = 0;
        for(int i = 0; i < n1; i++) {
            long long num = nums1[i];
            long long lo = 0;
            long long hi = n2 - 1;
            if(num < 0) {
                long long ans = 0;
                while(lo <= hi) {
                    long long mid2 = lo + (hi - lo) / 2;
                    if(1LL * nums2[mid2] * num <= mid) {
                        ans = n2 - mid2;
                        hi = mid2 - 1;
                    } else {
                        lo = mid2 + 1;
                    }
                }
                count += ans;
            } else {
                long long ans = 0;
                while(lo <= hi) {
                    long long mid2 = lo + (hi - lo) / 2;
                    if(1LL * nums2[mid2] * num <= mid) {
                        ans = mid2 + 1;
                        lo = mid2 + 1;
                    } else {
                        hi = mid2 - 1;
                    }
                }
                count += ans;
            }
        }
        return count >= k;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long lo = -1e10;
        long long hi = 1e10;
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(fun(mid, nums1, nums2, k)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
};