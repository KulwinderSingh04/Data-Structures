class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int ans = 0;
        vector<int> v;
        v.push_back(startTime[0]);
        int n = startTime.size();
        for(int i = 0; i < n - 1; i++) {
            v.push_back(startTime[i + 1] - endTime[i]);
        }
        v.push_back(eventTime - endTime.back());
        vector<int> prefix(n + 1), suffix(n + 1);
        for(int i = 1; i < n + 1; i++) {
            prefix[i] = max(prefix[i - 1], v[i - 1]);
        }
        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], v[i + 1]);
        }
        for(int i = 0; i < n; i++) {
            int free = 0;
            if(i > 0) free = max(free, prefix[i]);
            if(i < n - 1) free = max(free, suffix[i + 1]);
            int d = endTime[i] - startTime[i];
            if(free >= d) {
                ans = max(ans, v[i] + v[i + 1] + d);
            } else {
                ans = max(ans, v[i] + v[i + 1]);
            }
        }
        return ans;
        
    }
};