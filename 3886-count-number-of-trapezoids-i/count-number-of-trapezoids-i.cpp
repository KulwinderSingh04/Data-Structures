int MOD = 1e9 + 7;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    long long sum(vector<int>& a) {
        long long totalSum = 0, squareSum = 0;
        for(int x : a) {
            totalSum = (totalSum + x) % MOD;
            squareSum = (squareSum + 1LL * x * x % MOD) % MOD;
        }
        long long res = (1LL * totalSum * totalSum % MOD - squareSum + MOD) % MOD;
        res = (res * 1LL * ((MOD + 1) / 2)) % MOD;
        return res;
    }

    long long ncr(int n, int r) {
        if (r > n - r)
            r = n - r;
        long long res = 1;
        for (int i = 0; i < r; ++i) {
            res = res * (n - i) % MOD;
            res = res * modInverse(i + 1) % MOD;
        }
        return res;
    }

    long long modInverse(long long x) {
        long long res = 1, b = MOD - 2;
        while (b) {
            if (b & 1) res = res * x % MOD;
            x = x * x % MOD;
            b >>= 1;
        }
        return res;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int count = 1;
        vector<int> arr;
        int n = points.size();
        for(int i = 1; i < n; i++) {
            if(points[i][1] == points[i - 1][1]) count++;
            else {
                if(count != 1) arr.push_back(ncr(count, 2));
                count = 1;
            }
        }
        if(count != 1) arr.push_back(ncr(count, 2));
        return sum(arr);
    }
};
