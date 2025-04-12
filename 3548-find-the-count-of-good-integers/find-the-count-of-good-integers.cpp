class Solution {
public:
    long long fact(int n) {
        if(n == 1) return 1;
        return n * fact(n - 1);
    } 
    long long countGoodIntegers(int n, int k) {
        if(n == 1) return 9 / k;
        long long d = (n + 1) / 2;
        unordered_set<string> st;
        for(long long i = pow(10, d - 1); i < pow(10, d); i++){
            string num = to_string(i);
            // cout << num << " ";
            string v = num;
            if(n % 2 == 1) {
                v.pop_back();
            }
            reverse(v.begin(), v.end());
            num += v;
            if(stoll(num) % k == 0) {
                sort(num.begin(), num.end());
                st.insert(num);
            }
        }
        long long res = 0;
        cout << endl;
        for(auto x : st) {
            long long count = 0;
            long long t = x.size();
            unordered_map<char, long long> m;
            for(auto ch : x) {
                if(ch != '0') count++;
                m[ch]++;
            }
            long long ans = count * fact(t - 1);
            for(auto z : m) {
                ans /= fact(z.second);
            }
            res += ans;
        }
        return res;
    }
};