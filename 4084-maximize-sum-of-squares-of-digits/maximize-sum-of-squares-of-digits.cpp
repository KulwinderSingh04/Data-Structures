class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int t = 9;
        while(sum > 0 && t > 0) {
            if(sum - t >= 0) {
                ans += t + '0';
                sum -= t;
            } else t--;
        }
        if(ans.size() > num ||  ans == "") return "";
        while(ans.size() != num) ans += '0';
        return ans;
        
    }
};