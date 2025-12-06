class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<pair<int, int>> v(n);
        long long sum = 0;
        int t = 0;
        for(int i = 0; i < n; i++) {
            if(technique1[i] >= technique2[i]) {
                t++;
            }
            sum += max(technique1[i], technique2[i]);
            v[i] = {technique1[i], technique2[i]};
        }
        if(t >= k) return sum;
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return (a.second - a.first) < (b.second - b.first);
        });
        // cout << sum << endl;
        for(int i = 0; i < n; i++) {
            // cout << v[i].first << " " << v[i].second << endl;
            if(v[i].first >= v[i].second) continue;
            sum -= v[i].second;
            sum += v[i].first;
            t++;
            if(t >= k) return sum;
        }
        return -1;
    }
};