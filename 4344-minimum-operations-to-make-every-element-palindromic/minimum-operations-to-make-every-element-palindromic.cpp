bool flag = false;
vector<long long> od, ev;
class Solution {
public:
    long long makePal(long long num, int odd) {
        string s = to_string(num);
        string t = s;
        if(odd) t.pop_back();
        reverse(t.begin(), t.end());
        return stoll(s + t);
    }
    void init() {
        if(flag) return;
        for(int len = 1; len <= 10; len++) {
            int half = (len + 1) / 2;
            long long start = 1;
            for(int i = 0; i < half - 1; i++) start *= 10;
            long long end = start * 10;
            for(int num = start; num < end; num++) {
                long long a = makePal(num, len % 2);
                if(a % 2) od.push_back(a);
                else ev.push_back(a);
            }
        }
        flag = true;

    }
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        init();
        // for(int i = 1; i < 10; i++) pal.push_back(i);
        
        // vector<long long> odd, even;
        // for(auto x : pal) {
        //     if(x % 2) odd.push_back(x);
        //     else even.push_back(x);
        // }
        // sort(even.begin(), even.end());
        // sort(odd.begin(), odd.end());
        long long ans = 0;
        for(auto x : nums) {
            long long a = 1e18;
            if(x % 2) {
                int idx = lower_bound(od.begin(), od.end(), x) - od.begin();
                a = min(a, abs(od[idx] - x) / 2);
                if(idx - 1 >= 0) a = min(a, abs(od[idx - 1] - x) / 2);
                // a = min(a, abs(odd[idx + 1] - x) / 2);
                // cout << odd[idx] << endl;
                
            } else {
                int idx = lower_bound(ev.begin(), ev.end(), x) - ev.begin();
                a = min(a, abs(ev[idx] - x) / 2);
                if(idx - 1 >= 0) a = min(a, abs(ev[idx - 1] - x) / 2);
                // a = min(a, abs(even[idx + 1] - x) / 2);
                // cout << even[idx] << endl;
            }
            // cout << a << endl;
            ans += a;
        }
        return ans;
    }
};