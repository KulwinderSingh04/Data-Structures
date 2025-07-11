class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> v(n + 1);
        for(int i = 0; i < n + 1; i++) {
            int lo = max(0, i - ranges[i]);
            int hi = min(n, i + ranges[i]);
            v[lo] = max(v[lo], hi);   
        }
        int tap = 0;
        int mxEnd = 0, currEnd = 0;
        for(int i = 0; i < n + 1; i++) {
            if(i > mxEnd) return -1;
            if(i > currEnd) {
                tap++;
                currEnd = mxEnd; 
            }
            mxEnd = max(mxEnd, v[i]);
        } 
        return tap;
    }
};