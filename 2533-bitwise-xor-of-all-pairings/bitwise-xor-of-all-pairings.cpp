class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = 0;
        if(n1 % 2) {
            for(auto x : nums2) ans ^= x;
        }
        if(n2 % 2) {
            for(auto x : nums1) ans ^= x;
        }
        return ans;
    }
};