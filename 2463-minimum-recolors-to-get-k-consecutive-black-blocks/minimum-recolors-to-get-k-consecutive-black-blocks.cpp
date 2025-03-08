class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int w = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(i < k) {
                if(blocks[i] == 'W') w++;
            }
            else {
                ans = min(ans, w);
                if(blocks[i - k] == 'W') w--;
                if(blocks[i] == 'W') w++;
            }
        }
        ans = min(ans, w);
        return ans;
    }
};