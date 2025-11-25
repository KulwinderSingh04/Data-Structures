class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 1;
        unordered_set<int> st;
        for(int i = 1; i <= 1e5; i++) {
            int rem = num % k;
            if(rem == 0) return i;
            if(st.find(rem) != st.end()) return -1;
            num = rem * 10 + 1;
        }
        return -1;
    }
};