class Solution {
public:
    int fun(int n) {
        int count = 0;
        int sum = 0;
        for(int i = 1; i < sqrt(n); i++) {
            if(n % i == 0) {
                count++;
                sum += i;
            }
            if(n % (n / i) == 0) {
                count++;
                sum += n / i;
            }
            if(count > 4) return 0;
        }
        cout << sqrt(n) << " ";
        if((int)sqrt(n) * sqrt(n) == n) {
            count++;
            sum += (int)sqrt(n);
        }
        cout << count << " ";
        return count == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += fun(nums[i]);
        }
        return ans;
    }
};