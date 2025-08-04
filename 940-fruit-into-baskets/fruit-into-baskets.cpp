class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int count = 0;
        vector<int> hash(n);
        while(j < n) {
            if(hash[fruits[j]] == 0) count++;
            hash[fruits[j]]++;
            while(count > 2) {
                hash[fruits[i]]--;
                if(hash[fruits[i]] == 0) count--;
                i++;
            }
            ans = max(j - i + 1, ans);
            j++;
        }
        return ans;
    }
};