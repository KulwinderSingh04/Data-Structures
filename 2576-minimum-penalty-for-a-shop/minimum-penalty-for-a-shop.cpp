class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> noStart(n);
        vector<int> yesEnd(n);
        int yes = 0, no = 0;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') yes++;
            else no++;
            noStart[i] = no;
        }
        yes = 0, no = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(customers[i] == 'Y') yes++;
            else no++;
            yesEnd[i] = yes;
        }
        int ans = INT_MAX, idx = -1;
        for(int i = 0; i < n; i++) {
            int penalty = yesEnd[i];
            if(i - 1 >= 0) penalty += noStart[i - 1];
            if(ans > penalty) {
                ans = penalty;
                idx = i;
            }
        }
        if(ans > noStart.back()) {
            idx = n;
        }
        return idx;
    }
};