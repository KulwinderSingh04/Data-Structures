class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        long long closest = abs(nums2.back() - nums1[0]);
        int n = nums1.size();
        for(int i = 0; i < n; i++) {
            if(nums2.back() >= min(nums1[i], nums2[i]) && nums2.back() <= max(nums1[i], nums2[i])) {
                closest = 0;
                break;
            }
            if(min(nums1[i], nums2[i]) > nums2.back()) {
                closest = min(closest, 1LL * min(nums1[i], nums2[i]) - nums2.back());
            } else if(max(nums1[i], nums2[i]) < nums2.back()) {
                closest = min(closest, 1LL * nums2.back() - max(nums1[i], nums2[i]));
            }
        }
        ans += closest + 1;
        for(int i = 0; i < n; i++) {
            ans += abs(nums1[i] - nums2[i]);
        }
        return ans;
        
    }
};