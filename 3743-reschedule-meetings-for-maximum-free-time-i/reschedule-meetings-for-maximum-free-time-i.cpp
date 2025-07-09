class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = endTime.size();
        vector<int> v;
        v.push_back(startTime[0]);
        for(int i = 0; i < n - 1; i++) {
            v.push_back(startTime[i + 1] - endTime[i]);
        }
        v.push_back(eventTime - endTime.back());
        int ans = 0;
        int sum = 0;
        // for(auto x : v) cout << x << " ";
        for(int i = 0; i < v.size(); i++) {
            if(i <= k) {
                sum += v[i]; 
                ans = max(ans, sum);
            } else {
                ans = max(ans, sum);
                sum += v[i];
                sum -= v[i - k - 1];
            }
        }
        ans = max(ans, sum);
        return ans;
    }
};