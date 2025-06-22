class Solution {
public:
    bool isPrime(int a) {
        if(a == 1) return false;
        for(int i = 2; i < a; i++) {
            if(a % i == 0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x : nums) m[x]++;
        for(auto x : m) {
            if(isPrime(x.second)) return true;
        }
        return false;
    }
};