class Solution {
public:
    int minimumDeletions(vector<int>& arr) {
        int n = arr.size();
        int idx1 = 0, idx2 = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] > arr[idx1]) idx1 = i;
            if(arr[i] < arr[idx2]) idx2 = i;
        }
        return min(max(idx1, idx2) + 1, min(n - min(idx1, idx2), min(idx1, idx2) + 1 + n - max(idx1, idx2)));
    }
};