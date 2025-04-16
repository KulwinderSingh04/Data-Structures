class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<long long, long long> m;
        long long i = 0;
        long long j = 0;
        long long n = nums.size();
        long long ans = 0, count = 0;;
        while(j < n) {
            if(m.find(nums[j]) != m.end()) count += m[nums[j]];
            m[nums[j]]++;
            // if(count >= k) ans += n - j;
            while(count >= k) {
                ans += n - j;
                m[nums[i]]--; 
                if(m[nums[i]] == 0) m.erase(nums[i]);
                else count -= m[nums[i]];
                i++;
            }
            j++;
            
        }
        return ans;
    }
};