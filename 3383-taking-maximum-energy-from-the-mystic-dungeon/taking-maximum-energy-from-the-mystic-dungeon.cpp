class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int mx = INT_MIN;
        int n = energy.size();
        for(int i = n - 1; i >= 0; i--) {
            if(i + k < n) energy[i] += energy[i + k];
            mx = max(mx, energy[i]);
        }
        // for(int i = 0; i < n; i++) {
        //     int a = 0;
        //     for(int j = i; j < n; j += k) {
        //         a += energy[j];
        //     }
        //     mx = max(a, mx);
        // }   
        return mx;
    }
};