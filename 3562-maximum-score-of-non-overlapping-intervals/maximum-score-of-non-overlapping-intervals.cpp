class Solution {
public:
    int binSearch(int x, vector<vector<int>>& intervals) {
        int n = intervals.size();
        int lo = 0;
        int hi = n - 1;
        int ans = n;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(intervals[mid][0] > x) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
    long long add(vector<int>& v, unordered_map<int, int>& mp) {
        long long ans = 0;
        for(auto x : v) ans += mp[x];
        return ans;
    }
    bool isSmaller(vector<int>& v1, vector<int>& v2) {
        int i = 0;
        int n = v1.size();
        int m = v2.size();
        while(i < n && i < m) {
            if(v1[i] > v2[i]) {
                return false;
            } else if(v1[i] < v2[i]) return true;
            else i++;
        }
        if(i == n) return true;
        return false;
    }
    vector<int> fun(int i, int cnt, vector<vector<int>>& intervals, unordered_map<int, int>& mp, vector<map<int, vector<int>>>& dp) {
        int n = intervals.size();
        if(i == n || cnt == 0) {
            return {};
        }
        if(dp[i].find(cnt) != dp[i].end()) return dp[i][cnt];
        vector<int> v1;
        vector<int> v2;
        if(cnt > 0) {
            int idx = binSearch(intervals[i][1], intervals);
            v1.push_back(intervals[i][3]);
            auto vec = fun(idx, cnt - 1, intervals, mp, dp);
            for(auto x : vec) v1.push_back(x);
        }
        v2 = fun(i + 1, cnt, intervals, mp, dp);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        long long sum1 = add(v1, mp);
        long long sum2 = add(v2, mp);
        if(sum1 > sum2) return dp[i][cnt] = v1;
        else if(sum1 < sum2) return dp[i][cnt] = v2;
        else {
            if(isSmaller(v1, v2)) return dp[i][cnt] = v1;
            return dp[i][cnt] = v2;
        }
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        unordered_map<int, int> mp;
        int i = 0;
        int n = intervals.size();
        for(auto& x : intervals) {
            mp[i] = x[2];
            x.push_back(i++);
        }
        vector<map<int, vector<int>>> dp(n);
        sort(intervals.begin(), intervals.end());
        return fun(0, 4, intervals, mp, dp);
    }
};