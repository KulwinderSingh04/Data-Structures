public class Solution {
    public bool fun(int mid, int[] arr, int k) {
        int sum = 0;
        int students = 0;
        foreach(var x in arr) {
            // if(x > mid) return false;
            sum += x;
            if(sum > mid) {
                sum = x;
                students++;
            }
        }
        students++;
        return students <= k;
    }
    public int SplitArray(int[] arr, int k) {
        int n = arr.Length;
        if(n < k) return -1;
        int lo = arr.Max();
        int hi = arr.Sum();
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(mid, arr, k)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
}