class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int sz = -1;
        for(int i = 1; i < n ;i++) {
            if(sz == -1 || sz == arr[i] - arr[i - 1]) {
                sz =  arr[i] - arr[i - 1];
                ans.push_back({arr[i - 1], arr[i]});
            } else if(arr[i] - arr[i - 1] < sz) {
                while(ans.size()) ans.pop_back();
                sz = arr[i] - arr[i - 1];
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};