class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double ans = LLONG_MAX;
        vector<vector<double>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({wage[i] * 1.0 / quality[i], 1.0 * quality[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<double> pq;
        int sum = 0;
        for(int i = 0; i < k - 1; i++) {
            sum += v[i][1];
            pq.push(v[i][1]);
        }
        for(int i = k - 1; i < n; i++) {
            double ratio = v[i][0];
            sum += v[i][1];
            pq.push(v[i][1]);
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = min(ans, ratio * sum);
        }
        return ans;
    }
};