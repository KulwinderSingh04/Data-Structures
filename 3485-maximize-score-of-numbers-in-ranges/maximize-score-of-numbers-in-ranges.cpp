class Solution {
public:
    bool fun(int mid,vector<int>& start, int d) {
        long long a=start[0];
        for(int i=1;i<start.size();i++) {
            if(a+mid>start[i]+d) return false;
            if(a + mid>=start[i]) a+=mid;
            else a=start[i];
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        // vector<int> v;
        sort(start.begin(),start.end());
        long long n=start.size();
        long long lo=0;
        long long hi=start[n-1]+d;
        long long ans=0;
        while(lo<=hi) {
            int mid=lo+(hi-lo)/2;
            if(fun(mid,start,d)) {
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};