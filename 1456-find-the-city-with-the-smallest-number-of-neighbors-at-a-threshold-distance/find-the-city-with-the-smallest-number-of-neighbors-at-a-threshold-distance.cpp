class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int> (n,INT_MAX));
        for(int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }
        for(int i = 0; i < edges.size(); i++) {
            mat[edges[i][0]][edges[i][1]] = edges[i][2];
            mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < mat.size(); i++) {
                for(int j = 0; j < mat[0].size(); j++) {
                    if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][k] + mat[k][j] < mat[i][j]) {
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }
        int city = -1, maxWeight = n + 1;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(mat[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if(count <= maxWeight) {
                city = i;
                maxWeight = count;
            }
        }
        return city;
    }
};