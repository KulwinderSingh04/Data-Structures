public class Solution {
    public int LongestConsecutive(int[] nums) {
        int n = nums.Length;
        if(n == 0) return 0;
        HashSet<int> hs = new HashSet<int>();
        foreach(int x in nums) {
            hs.Add(x);
        }
        int ans = 0;
        foreach(int x in hs) {
            if(!hs.Contains(x - 1)) {
                int count = 0;
                int t = x;
                while(hs.Contains(t)) {
                    count++;
                    t++;
                }
                ans = Math.Max(count, ans);
            }
        }
        return ans;
    }
}