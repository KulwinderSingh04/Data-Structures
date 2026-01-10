public class Solution {
    public void SetZeroes(int[][] matrix) {
        int n = matrix.Length;
        int m = matrix[0].Length;
        int col = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    if(j == 0) {
                        col = 0;
                        matrix[i][0] = 0;
                    } else {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for(int j = 1; j < m; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 0; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 0; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(col == 0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}