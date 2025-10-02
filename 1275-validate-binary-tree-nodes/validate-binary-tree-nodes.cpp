class Solution {
public:
    int find(int x, vector<int>& par) {
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        x = find(x, par);
        y = find(y, par);
        if(rank[x] == rank[y]) {
            rank[x]++;
            par[y] = x;
        } else if(rank[x] > rank[y]) {
            par[y] = x;
        } else par[x] = y;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> par(n), rank(n);
        for(int i = 0; i < n; i++) par[i] = i;
        unordered_set<int> parSet;
        for(int i = 0; i < n; i++) {
            if(parSet.find(leftChild[i]) != parSet.end() || parSet.find(rightChild[i]) != parSet.end()) return false;
            if(leftChild[i] != -1) {
                if(find(i, par) != find(leftChild[i], par)) {
                    parSet.insert(leftChild[i]);
                    Union(i, leftChild[i], par, rank);
                } else return false;
            }
            if(rightChild[i] != -1) {
                if(find(i, par) != find(rightChild[i], par)) {
                    parSet.insert(rightChild[i]);
                    Union(i, rightChild[i], par, rank);
                } else return false;
            }
        }
        int count = 0;

        
        for(int i = 0; i < n; i++) if(par[i] == i) count++;
        return count == 1;
    }
};