class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(), nums.end(), greater<int> ());
        // vector<int> vMod1, vMod2;
        // int ans = 0;
        // for(auto x : nums) {
        //     if(x % 3 == 0) ans += x;
        //     else if(x % 3 == 1) vMod1.push_back(x);
        //     else vMod2.push_back(x);
        // }
        // int i1 = 0;
        // int i2 = 0;
        // int n1 = vMod1.size();
        // int n2 = vMod2.size();
        // while(i1 < n1 && i2 < n2) {
        //     int a = 0;
        //     int b = 0;
        //     int c = vMod1[i1] + vMod2[i2];
        //     int d = 0;
        //     if(i1 + 2 < n1) a = vMod1[i1] + vMod1[i1 + 1] + vMod1[i1 + 2];
        //     if(i2 + 2 < n2) b = vMod2[i2] + vMod2[i2 + 1] + vMod2[i2 + 2];
        //     if(i1 + 1 < n1 && i2 + 1 < n2) d = vMod1[i1] + vMod1[i1 + 1] + vMod2[i2] + vMod2[i2 + 1];
        //     if(a == max({a, b, c, d})) {
        //         i1 += 3;
        //         ans += a;
        //     } else if(b == max({a, b, c, d})) {
        //         i2 += 3;
        //         ans += b;
        //     } else if(c == max({a, b, c, d})) {
        //         ans += c;
        //         i1++;
        //         i2++;
        //     } else {
        //         ans += d;
        //         i1 += 2;
        //         i2 += 2;
        //     }
        // }
        // while(i1 + 2 < n1) {
        //     ans += vMod1[i1] + vMod1[i1 + 1] + vMod1[i1 + 2];
        //     i1 += 3;
        // }
        // while(i2 + 2 < n2) {
        //     ans += vMod2[i2] + vMod2[i2 + 1] + vMod2[i2 + 2];
        //     i2 += 3;
        // }
        // return ans;
        int n = nums.size();
        int sum = 0;
        vector<int> v1, v2;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(nums[i] % 3 == 1) {
                v1.push_back(nums[i]);
            } else if(nums[i] % 3 == 2) {
                v2.push_back(nums[i]);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if(sum % 3 == 0) return sum;
        else if(sum % 3 == 1) {
            int mn = INT_MAX;
            if(v2.size() > 1) mn = v2[0] + v2[1];
            if(v1.size()) mn = min(mn, v1[0]);
            return sum - mn;
        } else {
            int mn = INT_MAX;
            if(v1.size() > 1) mn = v1[0] + v1[1];
            if(v2.size()) mn = min(mn, v2[0]);
            return sum - mn;
        }
    }
};