public class Solution {
    public int FindKthPositive(int[] arr, int k) {
        int n = arr.Length;
        int lo = 0;
        int hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] - mid - 1 < k) {
                lo = mid + 1;
            } else hi = mid - 1;
        }
        if(hi == -1) {
            return k;
        }
        int num = arr[hi] - hi - 1;
        return arr[hi] + k - num;
    }
}