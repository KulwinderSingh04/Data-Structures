class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool flag = false;
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                flag = true;
                break;
            }
        }
        if(flag) return digits;
        digits.insert(digits.begin(), 1);
        return digits;
    }
};