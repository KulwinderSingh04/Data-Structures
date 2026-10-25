class Solution {
public:
    int fun(string s, vector<int>& vec) {
        int m1 = stoi(s.substr(0, 2));
        int ans = 0;
        if(m1 != 1) ans += vec[m1 - 2];
        ans += stoi(s.substr(3));
        return ans;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> vec = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for(int i = 1; i < 12; i++) vec[i] += vec[i - 1];
        int aa = fun(arriveAlice, vec);
        int la = fun(leaveAlice, vec);
        int ab = fun(arriveBob, vec);
        int lb = fun(leaveBob, vec);
        return min(la, lb) - max(aa, ab) + 1 >= 0 ? min(la, lb) - max(aa, ab) + 1 : 0;
    }
};