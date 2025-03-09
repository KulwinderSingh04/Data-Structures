class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums1[i], i, nums2[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        vector<long long> res(n);
        for(int i = 0; i < n; i++) {
            if(i > 0 && v[i][0] == v[i - 1][0]) res[v[i][1]] = res[v[i - 1][1]];
            else res[v[i][1]] = sum;
            sum += v[i][2];
            pq.push(v[i][2]);
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            } 
        }
        return res;
    }
};