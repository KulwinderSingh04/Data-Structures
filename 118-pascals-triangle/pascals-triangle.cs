public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        IList<IList<int>> li = new List<IList<int>>(numRows);
        for(int i = 0; i < numRows; i++) {
            IList<int> v = new List<int>(i + 1);
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    v.Add(1);
                } else {
                    v.Add(li[i - 1][j] + li[i - 1][j - 1]);
                }
            }
            li.Add(v);
        }
        return li;
    }
}