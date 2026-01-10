public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        int n = matrix.Length;
        int m = matrix[0].Length;
        IList<int> li = new List<int>();
        int mnR = 0, mxR = n - 1, mnC = 0, mxC = m - 1;
        while(mnR <= mxR && mnC <= mxC) {
            for(int i = mnC; i <= mxC; i++) {
                li.Add(matrix[mnR][i]);
            }
            mnR++;
            if(mnR > mxR) break;
            for(int i = mnR; i <= mxR; i++) {
                li.Add(matrix[i][mxC]);
            }
            mxC--;
            if(mnC > mxC) break;
            for(int i = mxC; i >= mnC; i--) {
                li.Add(matrix[mxR][i]);
            }
            mxR--;
            
            if(mnR > mxR) break;
            for(int i = mxR; i >= mnR; i--) {
                li.Add(matrix[i][mnC]);
            }
            mnC++;
            if(mnC > mxC) break;
        }
        return li;
    }
}