class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int del = 0;
        vector<bool> v(strs.size() - 1, false);
        for(int j = 0; j < strs[0].size(); j++) {
            bool flag = true;
            for(int i = 0; i < strs.size() - 1; i++) {
                if(strs[i][j] > strs[i + 1][j] && v[i] == false) {
                    del++;
                    flag = false;
                    break;
                }
            }
            if(flag == false) {
                continue;
            }
            for(int i = 0; i < strs.size() - 1; i++) {
                v[i] = v[i] | (strs[i][j] < strs[i + 1][j]);
            }
        }
        return del;
    }
};