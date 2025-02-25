class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int zero = 0, one = 0;
        int sum = 0, ans = 0;
        int n = arr.size();
        zero = 1;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum % 2 == 0) {
                ans += one;
                zero++;
            }
            else {
                ans += zero;
                one++;
            }
            ans %= 1000000007;
        }
        return ans;
    }
};