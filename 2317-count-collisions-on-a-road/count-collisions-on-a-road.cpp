class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0;
        int i1 = 0;
        while(i1 < n && directions[i1] == 'L') i1++;
        int i2 = n - 1;
        while(i2 >= 0 && directions[i2] == 'R') i2--;
        for(int i = i1; i <= i2; i++) {
            if(directions[i] == 'L' || directions[i] == 'R') ans++;
        }
        return ans;
    }
};