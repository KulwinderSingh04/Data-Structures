public class Solution {
    public int MaxProduct(int[] nums) {
        int n = nums.Length;
        int pr = 1;
        int sf = 1;
        int ans = int.MinValue;
        for(int i = 0; i < n; i++) {
            if(pr == 0) pr = 1;
            if(sf == 0) sf = 1;
            pr *= nums[i];
            sf *= nums[n - 1 - i];
            ans = Math.Max(ans, Math.Max(pr, sf));
        }
        return ans;
    }
}