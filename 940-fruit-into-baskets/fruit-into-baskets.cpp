class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> hash(n);
        int i = 0;
        int j = 0;
        int count = 0, ans = 0;
        while(j < n) {
            if(hash[fruits[j]] == 0) count++;
            hash[fruits[j]]++;
            while(count > 2) {
                hash[fruits[i]]--;
                if(hash[fruits[i]] == 0) count--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};