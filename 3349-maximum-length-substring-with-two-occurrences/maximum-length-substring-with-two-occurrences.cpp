class Solution {
public:
    int maximumLengthSubstring(string nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 1;
        unordered_map<int, int> hash;
        while(j < n) {
            hash[nums[j]]++;
            while(hash[nums[j]] > 2) {
                hash[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};