class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        bool flag =false;
        int i = 0;
        int count = 0;
        for(int j = 1; j < n + k - 1; j++) {
            if(colors[j % n] != colors[(j - 1) % n]) {
                if(j - i >= k - 1) count++;
            }
            else i = j;

        }
        return count;
    }
};