public class Solution {
    public void merge(int[] nums, int lo, int mid, int hi) {
        int n = nums.Length;
        int[] a = new int[mid - lo + 1];
        int[] b = new int[hi - mid];
        for(int ii = lo; ii <= mid; ii++) {
            a[ii - lo] = nums[ii];
        }
        for(int ii = mid + 1; ii <= hi; ii++) {
            b[ii - mid - 1] = nums[ii];
        }
        int i = 0;
        int j = 0;
        int k = lo;
        while(i < a.Length && j < b.Length) {
            if(a[i] <= b[j]) {
                nums[k++] = a[i++];
            } else {
                nums[k++] = b[j++];
            }
        }
        while(i < a.Length) {
            nums[k++] = a[i++];
        }
        while(j < b.Length) {
            nums[k++] = b[j++];
        }
        
    }
    public void mergeSort(int[] nums, int lo, int hi, ref int ans) {
        if(lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mid, ref ans);
        mergeSort(nums, mid + 1, hi, ref ans);

        int i = lo;
        int j = mid + 1;
        while(i <= mid && j <= hi) {
            if(nums[i] > 2.0 * nums[j]) {
                ans += mid - i + 1;
                j++;
            } else i++;
        }
        merge(nums, lo, mid, hi);
    }
    public int ReversePairs(int[] nums) {
        int n = nums.Length;
        int ans = 0;
        mergeSort(nums, 0, n - 1,ref ans);
        return ans;
    }
}