class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int ans = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            m[digits[i]]++;
        }
        for(int i=100;i<1000;i++) {
            if(i%2==1) continue;
            int num=i;
            int a=num%10;
            num/=10;
            int b=num%10;
            num/=10;
            int c=num%10;
            num/=10;
            if(m.find(a)!=m.end()) {
                m[a]--;
                if(m[a]==0) m.erase(a);
                if(m.find(b)!=m.end()) {
                    m[b]--;
                    if(m[b]==0) m.erase(b);
                    if(m.find(c)!=m.end()) {
                        ans++;
                    }
                    m[b]++;
                }
                m[a]++;
            }
        }
        return ans;
    }
};