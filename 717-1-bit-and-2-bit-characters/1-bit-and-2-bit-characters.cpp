class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while(i < n) {
            if(bits[i] == 1) {
                i += 2;
            } else {
                if(i == n - 1) return true;
                i++;
            }
        }
        return false;
    }
};