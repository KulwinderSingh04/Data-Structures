class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int t1 = k;
        int a1 = 0, mx1 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'N' || s[i] == 'W') {
                a1++;
                mx1 = max(mx1, a1);
                
            } else {
                if(t1) {
                    a1++;
                    t1--;
                    mx1 = max(mx1, a1);
                } else {
                    a1--;
                }
            }
        }

        int t2 = k;
        int a2 = 0, mx2 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'S' || s[i] == 'E') {
                a2++;
                mx2 = max(mx2, a2);
                
            } else {
                if(t2) {
                    a2++;
                    t2--;
                    mx2 = max(mx2, a2);
                } else {
                    a2--;
                }
            }
        }

        int t3 = k;
        int a3 = 0, mx3 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'N' || s[i] == 'E') {
                a3++;
                mx3 = max(mx3, a3);
                
            } else {
                if(t3) {
                    a3++;
                    t3--;
                    mx3 = max(mx3, a3);
                } else {
                    a3--;
                }
            }
        }

        int t4 = k;
        int a4 = 0, mx4 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'S' || s[i] == 'W') {
                a4++;
                mx4 = max(mx4, a4);
                
            } else {
                if(t4) {
                    a4++;
                    t4--;
                    mx4 = max(mx4, a4);
                } else {
                    a4--;
                }
            }
        }

        return max(max(mx3, mx4), max(mx1, mx2));
    }
};