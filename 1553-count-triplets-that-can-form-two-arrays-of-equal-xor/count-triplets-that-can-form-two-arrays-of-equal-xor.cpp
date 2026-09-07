class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];
        for(int i = 1; i < n; i++) pref[i] = pref[i - 1] ^ arr[i];
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j; k < n; k++) {
                    int l = pref[j - 1];
                    if(i > 0) l ^= pref[i - 1];
                    int r = pref[k] ^ pref[j - 1];
                    if(l == r) count++;
                }
            }
        }
        return count;
    }
};