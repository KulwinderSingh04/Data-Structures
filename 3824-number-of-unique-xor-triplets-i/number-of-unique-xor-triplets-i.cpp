class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int a = 0;
        while(n != 0) {
            a++;
            n /= 2;
        }
        return pow(2, a);
    }
};