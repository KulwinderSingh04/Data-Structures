class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        vector<int> suff(n);
        int m = word2.size();
        int j = m - 1;
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(j >= 0 && word1[i] == word2[j]) {
                cnt++;
                j--;
            }
            suff[i] = cnt;
        }
        // return suff;
        j = 0;
        int suffLeft = 0;
        bool flag = false;
        for(int i = 0; i < n; i++) {
            int left = j;
            int right = m - 1 - j;
            int suffRight = 0;
            if(i + 1 < n) suffRight = suff[i + 1];
            if(j < m && word1[i] != word2[j] && suffLeft >= left && suffRight >= right) {
                word1[i] = word2[j];
                flag = true;
                break;
            }
            if(j < m && word1[i] == word2[j]) {
                suffLeft++;
                j++;
            }
        }
        // if(flag == false) return {};
        int i = 0;
        j = 0;
        vector<int> ans;
        while(i < n && j < m) {
            if(j < m && word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            i++;
        }
        if(j != m) return {};
        return ans;
    }
};