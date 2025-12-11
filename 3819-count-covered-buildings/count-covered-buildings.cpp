class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end());
        set<vector<int>> st;
        for(int i = 1; i < buildings.size() - 1; i++) {
            if(buildings[i - 1][0] == buildings[i][0] && buildings[i][0] == buildings[i + 1][0]) st.insert(buildings[i]);
        }
        sort(buildings.begin(), buildings.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int ans = 0;
        for(int i = 1; i < buildings.size() - 1; i++) {
            if(buildings[i - 1][1] == buildings[i][1] && buildings[i][1] == buildings[i + 1][1] && st.find(buildings[i]) != st.end()) {
                ans++;
            }
        }
        return ans;
    }
};