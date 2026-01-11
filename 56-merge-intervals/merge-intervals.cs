public class Solution {
    public int[][] Merge(int[][] intervals) {
        int n = intervals.Length;
        List<int[]> li = new List<int[]>();
        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));
        for(int i = 0; i < n; i++) {
            if(li.Count() == 0 || li.Last()[1] < intervals[i][0]) {
                li.Add(intervals[i]);
            } else {
                li.Last()[1] = Math.Max(li.Last()[1], intervals[i][1]);
            }
        }
        return li.ToArray();
    }
}