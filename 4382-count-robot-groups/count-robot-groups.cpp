class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size();
        int cnt = n;
        int maxSpeed= speed[n - 1];
        for(int i = n - 1; i > 0; i--) {
            if(position[i] - position[i - 1] <= distance) {
                cnt--;
            } else if(speed[i - 1] > maxSpeed) {
                cnt--;
            } else {
                maxSpeed = speed[i - 1];
            }
                
        }
        return cnt;
    }
};