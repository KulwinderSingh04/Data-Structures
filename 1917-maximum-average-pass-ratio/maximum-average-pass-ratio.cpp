class Solution {
public:
    typedef pair<double, int> pp;
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        int n = classes.size();
        priority_queue<pp> pq;
        for(int i = 0; i < n; i++) {
            double old_ratio = 1.0 * classes[i][0] / classes[i][1];
            double new_ratio = (1.0 * classes[i][0] + 1) / (classes[i][1] + 1);
            pq.push({new_ratio - old_ratio, i});
        }
        
        while(extra--) {
            auto curr = pq.top();
            pq.pop();
            double delta = curr.first;
            int idx = curr.second;
            classes[idx][0]++;
            classes[idx][1]++;
            double old = 1.0 * classes[idx][0] / classes[idx][1];
            pq.push({(1.0 * classes[idx][0] + 1) / (classes[idx][1] + 1) - old, idx});
        }
        double ans = 0;
        for(auto x : classes) ans += 1.0 * x[0] / x[1];
        return ans / n;
    }
};