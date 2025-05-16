class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totSum = 0;
        int n = cardPoints.size();
        int a = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            if(i < n - k) {
                sum += cardPoints[i];
                a = sum;
            } else {
                sum += cardPoints[i];
                sum -= cardPoints[i - n + k];
                a = min(a, sum);
            }
            totSum += cardPoints[i];
        }
        return totSum - a;
    }
};