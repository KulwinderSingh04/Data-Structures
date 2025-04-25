bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] > b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(boxTypes[i][0] <= truckSize) {
                truckSize -= boxTypes[i][0];
                ans += boxTypes[i][0] * boxTypes[i][1];
            } else {
                ans += truckSize * boxTypes[i][1];
                break;
            }

        }
        return ans;
    }
};