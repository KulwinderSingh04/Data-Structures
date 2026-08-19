class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        map<int, unordered_set<int>> mp;
        for(auto x : reservedSeats) {
            mp[x[0]].insert(x[1]);
        }
        int prevRow = 0;
        int ans = 0;
        for(auto row : mp) {
            auto& vec = row.second;
            int val = 2;
            int r = row.first;
            ans += (r - prevRow - 1) * 2;
            if(vec.find(2) == vec.end() && vec.find(3) == vec.end() && vec.find(4) == vec.end() && vec.find(5) == vec.end()) {
                if(vec.find(6) == vec.end() && vec.find(7) == vec.end() && vec.find(8) == vec.end() && vec.find(9) == vec.end()) ans += 2;
                else ans += 1;
            } else if(vec.find(4) == vec.end() && vec.find(5) == vec.end() && vec.find(6) == vec.end() && vec.find(7) == vec.end()) {
                ans += 1;
            } else if(vec.find(6) == vec.end() && vec.find(7) == vec.end() && vec.find(8) == vec.end() && vec.find(9) == vec.end()) {
                ans += 1;

            }
            prevRow = r;
        }
        ans += (n - prevRow) * 2;
        return ans;
    }
};