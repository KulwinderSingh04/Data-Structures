class Solution {
public:
    typedef pair<int, int> pp;
    vector<int> fun(int mx) {
        vector<int> v(mx + 1, 1);
        for(int i = 2; i <= mx; i++) {
            if(v[i] == 0) continue;
            for(int j = 2 * i; j <= mx; j += i) {
                v[j] = 0;
            }
        }
        vector<int> ans;
        for(int i = 2; i < mx + 1; i++) if(v[i] == 1) ans.push_back(i);
        return ans;
    }
    void funPrime(vector<int>& primeScore, vector<int>& nums, vector<int>& primes) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < primes.size(); j++) {
                int count = 0;
                while(nums[i] % primes[j] == 0) {
                    nums[i] /= primes[j];
                    count++;
                }
                if(count) primeScore[i]++;
                if(primes[j] * primes[j] > nums[i]) break;
            }
            if(nums[i] > 1) {
                primeScore[i]++;
            }
        }
    }
    long long pow(long long a, long long b) {
        if(b == 1) return a;
        long long r = pow(a, b / 2);
        long long res = (r * r) % 1000000007;
        if(b % 2 == 1) return (res * a) % 1000000007;
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pp> sortedNum;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            sortedNum.push_back({nums[i], i});
        }
        sort(sortedNum.begin(), sortedNum.end());
        reverse(sortedNum.begin(), sortedNum.end());
        vector<int> primeScore(n);
        vector<int> primes = fun(mx);
        funPrime(primeScore, nums, primes);
        vector<int> nge(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() && primeScore[st.top()] <= primeScore[i]) st.pop();
            if(st.size() == 0) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }

        vector<int> pgee(n);
        stack<int> gt;
        for(int i = 0; i < n; i++) {
            while(gt.size() && primeScore[gt.top()] < primeScore[i]) gt.pop();
            if(gt.size() == 0) pgee[i] = -1;
            else pgee[i] = gt.top();
            gt.push(i);
        }
        // for(int i = 0; i < n; i++) cout << primeScore[i] << " ";
        // cout << endl;
        // for(int i = 0; i < n; i++) cout << nge[i] << " ";
        // cout << endl;
        // for(int i = 0; i < n; i++) cout << pgee[i] << " ";
        long long score = 1;
        for(int i = 0; i < n; i++) {
            long long ele = sortedNum[i].first;
            int idx = sortedNum[i].second;
            long long op = 1LL * (idx - pgee[idx]) * (nge[idx] - idx);
            // cout << op << " ";
            score = (score * pow(ele, min((long long)k, op))) % 1000000007;
            k -= min((long long)k, op);
            if(k == 0) break;
        }
        return score % 1000000007;
    }
};