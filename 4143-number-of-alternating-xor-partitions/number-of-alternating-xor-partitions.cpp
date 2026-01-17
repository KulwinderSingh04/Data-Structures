class Solution {
public:
    static const int MOD = 1e9 + 7;
    unordered_map<long long, int> memo;

    /*
      index        -> current position in nums
      currentXor   -> XOR accumulated so far
      isTeam1Turn  -> true if Team 1's turn, false if Team 2's turn
    */
    int solve(int index,int currentXor,bool isT1Turn,vector<int>& nums,int t1,int t2) {
        // Base case: reached end of array
        if (index == nums.size()) {
            if ((isT1Turn && currentXor == t1) ||
                (!isT1Turn && currentXor == t2)) {
                return 1;
            }
            return 0;
        }

        // Encode state into a single key for memoization
        long long stateKey =((long long)index << 32) |((long long)currentXor << 1) | isT1Turn;

        if (memo.count(stateKey))
            return memo[stateKey];

        long long ways = 0;

        // Option 1: Stop current segment & switch turn
        if ((isT1Turn && currentXor == t1) ||
            (!isT1Turn && currentXor == t2)) {
            ways += solve(index + 1,nums[index],!isT1Turn,nums,t1,t2);
        }

        // Option 2: Continue XOR with same num
        ways += solve(index + 1,currentXor ^ nums[index],isT1Turn,nums,t1,t2);

        return memo[stateKey] = ways % MOD;
    }

    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        // Start from index 1, with nums[0] as initial XOR
        return solve(1, nums[0], true, nums, target1, target2);
    }
};