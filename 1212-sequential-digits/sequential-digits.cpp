class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        int factor = 1;
        int num = 1;
        int x = 1;
        string s = "1";
        vector<int> ans;
        while(num <= high) {
            if(num % 10 == 0) return ans;
            if(num % 10 == 9) {
                if(num >= low && num <= high) ans.push_back(num);
                int rem = x % 10;
                x = x * 10 + rem + 1;
                num = x;
                factor = factor * 10 + 1;
            }
            if(num >= low && num <= high) ans.push_back(num);
            num += factor;
        }
        return ans;
    }
};