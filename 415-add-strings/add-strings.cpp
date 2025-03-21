class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1; 
        while(i >= 0 && j >= 0) {
            int a = num1[i] + num2[j] - 96 + carry;
            if(a > 9) {
                carry = 1;
                a -= 10;
            }
            else carry = 0;
            ans += a + 48;
            i--;
            j--;
        }
        if(i < 0) {
            while(j >= 0) {
                int a = num2[j] - 48 + carry;
                if(a > 9) {
                    carry = 1;
                    a -= 10;
                }
                else carry = 0;
                ans += a + 48;
                j--;
            }
        }
        else {
            while(i >= 0) {
                int a = num1[i] - 48 + carry;
                if(a > 9) {
                    carry = 1;
                    a -= 10;
                }
                else carry = 0;
                ans += a + 48;
                i--;
            }
        }
        if(carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};