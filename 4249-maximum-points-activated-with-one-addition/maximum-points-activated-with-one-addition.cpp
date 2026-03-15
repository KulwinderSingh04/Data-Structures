class Solution {
public:
    int find(int i, vector<int>& par) {
        if(par[i] == i) return i;
        return par[i] = find(par[i], par);
    }
    void Union(int x, int y, vector<int>& par, vector<int>& size) {
        x = find(x, par);
        y = find(y, par);
        if(x == y) return;
        if(size[x] >= size[y]) {
            size[x] += size[y];
            par[y] = x;
        } else {
            size[y] += size[x];
            par[x] = y;
        }
    }
    typedef pair<int, int> pp;
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        map<pp, int> mp;
        int val = 0;
        for(int i = 0; i < n; i++) {
            mp[{points[i][0], points[i][1]}] = val++;
        }
        sort(points.begin(), points.end());
        vector<int> par(val), size(val, 1);
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < n - 1; i++) {
            int a = mp[{points[i][0], points[i][1]}];
            int b = mp[{points[i + 1][0], points[i + 1][1]}];
            // cout << (points[i][0] == points[i + 1][0]) << endl;
            if(points[i][0] == points[i + 1][0] && find(a, par) != find(b, par)) {
            // cout << a << " " << b << endl;
                Union(a, b, par, size);
            }
        }
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        for(int i = 0; i < n - 1; i++) {
            int a = mp[{points[i][0], points[i][1]}];
            int b = mp[{points[i + 1][0], points[i + 1][1]}];
            if(points[i][1] == points[i + 1][1] && find(a, par) != find(b, par)) {
                Union(a, b, par, size);
            }
        }
        vector<int> v;
        for(int i = 0; i < n; i++) {
            if(par[i] == i) {
                v.push_back(size[i]);
            }
        }
        for(int i = 0; i < n; i++) cout << par[i] << endl;
        cout << endl;
        for(int i = 0; i < v.size(); i++) cout << v[i] << endl;
        sort(v.begin(), v.end(), greater<int> ());
        int ans = v[0] + 1;
        if(v.size() > 1) ans += v[1];
        return ans;
    }
};