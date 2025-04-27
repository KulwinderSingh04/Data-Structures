
bool cmp(vector<int>& a, vector<int>& b) {
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        vector<vector<int>> v1 = buildings;
        vector<vector<int>> v2 = buildings;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), cmp);
        map<vector<int>, int> m;
        int ans = 0;
        for(int i = 0; i < v2.size(); i++) m[v2[i]] = i;
        for(int i = 1; i < v1.size() - 1; i++) {
            if(v1[i - 1][0] == v1[i][0] && v1[i + 1][0] == v1[i][0]) {
                int idx = m[v1[i]];
                if(v2[idx - 1][1] == v2[idx][1] && v2[idx + 1][1] == v2[idx][1]) {
                    ans++;
                }
            }
        }
        // for(int i = 0; i < v1.size(); i++) {
        //     cout << v1[i][0] << " " << v1[i][1] << endl;
        // }
        // cout << endl;
        // for(int i = 0; i < v1.size(); i++) {
        //     cout << v2[i][0] << " " << v2[i][1] << endl;
        // }
        return ans;
    }
};