class Solution {
public:
    bool fun(int mid, vector<long long>& vec, long long k) {
        int n = vec.size();
        long long surplus = 0;
        for(int i = 0; i < n; i++) {
            surplus += vec[i] - mid < 0 ? 0 : vec[i] - mid;
        }
        return surplus <= k;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back(abs(nums1[i] - nums2[i]));
        }
        long long sum = accumulate(vec.begin(), vec.end(), 0LL);
        sort(vec.begin(), vec.end());
        long long lo = 0;
        long long hi = sum;
        int val = sum;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(mid, vec, k1 + k2)) {
                val = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        // cout << val << endl;
        long long ans = 0;
        long long surplus = 0;
        for(int i = 0; i < n; i++) {
            surplus += vec[i] - val < 0 ? 0 : vec[i] - val;
            if(vec[i] > val) vec[i] = val;
        }
        // cout << surplus;
        long long rem = k1 + k2 - surplus;
        for(int i = 0; i < n; i++) {
            if(vec[i] < val) ans += vec[i] * vec[i];
            else {
                if(rem > 0) ans += max(0LL, (vec[i] - 1)) * max(0LL,(vec[i] - 1));
                else ans += vec[i] * vec[i];
                rem--;
            }
            // cout << ans << endl;
        }
        return ans;
    }
};