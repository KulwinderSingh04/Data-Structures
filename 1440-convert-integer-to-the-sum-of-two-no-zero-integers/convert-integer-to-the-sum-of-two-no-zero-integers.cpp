class Solution {
public:
    bool safe(int a, int b) {
        string aa = to_string(a);
        string bb = to_string(b);
        for(auto x : aa) if(x == '0') return false;
        for(auto x : bb) if(x == '0') return false;
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int t = 1;
        while(true){
            if(safe(n - t, t)) return {n - t, t};
            t++;
        }
        return {};
    }
};