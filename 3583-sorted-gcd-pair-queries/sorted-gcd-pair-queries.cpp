class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> gcdPairCount(mx + 1);
        for(auto x : nums) {
            for(int j = 1; j * j <= x; j++) {
                if(x % j == 0) {
                    int r1 = j;
                    int r2 = x / j;
                    gcdPairCount[r1]++;
                    if(r1 != r2) gcdPairCount[r2]++;
                }
            }
        }
        for(int i = mx; i >= 1; i--) {
            gcdPairCount[i] = (1LL * gcdPairCount[i] * (gcdPairCount[i] - 1) / 2);
            for(int j = 2 * i; j <= mx; j += i) {
                gcdPairCount[i] -= gcdPairCount[j];
            }
        }
        for(int i = 1; i < mx + 1; i++) gcdPairCount[i] += gcdPairCount[i - 1];
        // for(int i = 1; i < mx + 1; i++) gcdPairCount[i]--;
        // return gcdPairCount;
        vector<int> ans;
        for(auto q : queries) {
            int idx = lower_bound(gcdPairCount.begin() + 1, gcdPairCount.end(), q + 1) - gcdPairCount.begin();
            // cout << idx << " ";
            // if(gcdPairCount[idx] == q) idx++;
            ans.push_back(idx);
        }
        return ans;
    }
};