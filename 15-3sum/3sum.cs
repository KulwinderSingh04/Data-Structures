public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        IList<IList<int>> li = new List<IList<int>>();
        HashSet<(int, int, int)> hs = new HashSet<(int, int, int)>();
        int n = nums.Length;
        Array.Sort(nums);
        for(int i = 0; i < n; i++) {
            int newTarget = -nums[i];
            Dictionary<int, int> dt = new Dictionary<int, int>();
            for(int j = i + 1; j < n; j++) {
                if(dt.ContainsKey(newTarget - nums[j])) {
                    List<int> v = new List<int>();
                    hs.Add((nums[i], newTarget - nums[j], nums[j]));
                }
                dt[nums[j]] = j;
            }
        }
        HashSet<string> hst = new HashSet<string>();
        
        foreach((int, int, int) x in hs) {
            List<int> v = new List<int>();
            v.Add(x.Item1);
            v.Add(x.Item2);
            v.Add(x.Item3);
            li.Add(v);
        }
        return li;
    }
}