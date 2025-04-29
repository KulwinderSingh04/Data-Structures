class Solution {
public:
    typedef pair<int, int> pp;
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pp> v;
        for(int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }
        int count = 1;
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            if(i == 0 || v[i].first != v[i - 1].first) {
                arr[v[i].second] = count++;
            } else {
                arr[v[i].second] = arr[v[i - 1].second];
            }
        }
        return arr;
    }
};