class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<long long> count(32), a2(32);
        for(int i = 0; i < n2; i++) {
            for(int bit = 0; bit < 32; bit++) {
                if(arr2[i] & (1 << bit)) a2[bit]++;
            }
        }
        for(int i = 0; i < n1; i++) {
            for(int bit = 0; bit < 32; bit++) {
                if(arr1[i] & (1 << bit))  {
                    count[bit] += a2[bit];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(count[i] % 2) ans |= (1 << i);
        }
        return ans;

    }
};