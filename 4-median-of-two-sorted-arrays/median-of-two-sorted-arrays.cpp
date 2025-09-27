class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int tot = n + m;
        double a = 0, b = 0;
        int count = 0;
        while(i < n && j < m) {
            if(nums1[i] > nums2[j]) {
                if(count == (tot / 2 - 1)) a = nums2[j];
                if(count == (tot / 2)) b = nums2[j];
                count++;
                j++;
            } else {
                if(count == (tot / 2 - 1)) a = nums1[i];
                if(count == (tot / 2)) b = nums1[i];
                count++;
                i++;
            }
            if(count > (tot / 2)) break;
        }
        if(i == n) {
            while(j < m) {
                if(count == (tot / 2 - 1)) a = nums2[j];
                if(count == (tot / 2)) b = nums2[j];
                count++;
                j++;
                if(count > (tot / 2)) break;
            }
            
        } else {
            while(i < n) {
                if(count == (tot / 2 - 1)) a = nums1[i];
                if(count == (tot / 2)) b = nums1[i];
                count++;
                i++;
                if(count > (tot / 2)) break;
            }
        }
        return tot % 2 ? b : (a + b) / 2.0;
    }
};