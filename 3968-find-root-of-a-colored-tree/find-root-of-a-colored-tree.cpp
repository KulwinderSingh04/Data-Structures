class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = edges.size() + 1;
        vector<int> ind(n), out(n);
        for(auto x : edges) {
            if(colors[x[0]] == colors[x[1]]) return -1;
            if(colors[x[0]] == 'R') {
                if(colors[x[1]] == 'B') {
                    out[x[0]]++;
                    ind[x[1]]++;
                } else {
                    out[x[1]]++;
                    ind[x[0]]++;
                }
            } else if(colors[x[0]] == 'B') {
                if(colors[x[1]] == 'W') {
                    out[x[0]]++;
                    ind[x[1]]++;
                } else {
                    out[x[1]]++;
                    ind[x[0]]++;
                }
            } else {
                if(colors[x[1]] == 'R') {
                    out[x[0]]++;
                    ind[x[1]]++;
                } else {
                    out[x[1]]++;
                    ind[x[0]]++;
                }
            }
        }
        if(*max_element(out.begin(), out.end()) > 2) return -1;
        if(*max_element(ind.begin(), ind.end()) > 1) return -1;
        if(count(ind.begin(), ind.end(), 0) != 1) return -1;
        return find(ind.begin(), ind.end(), 0) - ind.begin();
    }
};