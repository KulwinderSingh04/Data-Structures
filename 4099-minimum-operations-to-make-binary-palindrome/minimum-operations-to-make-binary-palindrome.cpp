class Solution {
public:
    int fun1(int num) {
        int n = num;
        int ans = 0;
        while(true) {
            string str = "";
            int t = num;
            while(num) {
                str += num % 2 + '0';
                num /= 2;
            }
            int i = 0;
            int j = str.size() - 1;
            bool flag = true;
            // cout << str << " ";
            while(i < j) {
                if(str[i] != str[j]) {
                    flag = false;
                    break;
                }
                i++;
                j--;
            }
            if(flag) return t - n;
            num = t + 1;
        }
        
        return ans;
    }
    int fun2(int num) {
        int n = num;
        int ans = 0;
        while(true) {
            string str = "";
            int t = num;
            while(num) {
                str += num % 2 + '0';
                num /= 2;
            }
            int i = 0;
            int j = str.size() - 1;
            bool flag = true;
            // cout << str << " ";
            while(i < j) {
                if(str[i] != str[j]) {
                    flag = false;
                    break;
                }
                i++;
                j--;
            }
            if(flag) return n - t;
            num = t - 1;
        }
        
        return ans;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = min(fun1(nums[i]), fun2(nums[i]));
        }
        return ans;
    }
};