class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> leftPush(n, -1), rightPush(n, -1);
        if(dominoes[0] == 'R') leftPush[0] = 0;
        for(int i = 1; i < n; i++) {
            if(dominoes[i] == 'R') leftPush[i] = i;
            else if(dominoes[i] == 'L') leftPush[i] = -1;
            else leftPush[i] = leftPush[i - 1];
        }
        // for(int i = 0; i < n; i++) cout << leftPush[i] << " ";
        // cout << endl;
        if(dominoes[n - 1] == 'L') rightPush[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(dominoes[i] == 'L') rightPush[i] = i;
            else if(dominoes[i] == 'R') rightPush[i] = -1;
            else rightPush[i] = rightPush[i + 1];
        }
        // for(int i = 0; i < n; i++) cout << rightPush[i] << " ";
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(dominoes[i] != '.') {
                ans += dominoes[i];
            } else {
                if(leftPush[i] == -1 && rightPush[i] == -1) {
                    ans += '.';
                } else if(leftPush[i] == -1) {
                    ans += 'L';
                } else if(rightPush[i] == -1) {
                    ans += 'R';
                } else {
                    if(i - leftPush[i] == rightPush[i] - i) {
                        ans += '.';
                    } else if(i - leftPush[i] > rightPush[i] - i) {
                        ans += 'L';
                    } else {
                        ans += 'R';
                    }
                }
            }
        }
        return ans;
    }
};