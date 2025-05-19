class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_set<int> s;
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        s.insert(nums[0]);
        s.insert(nums[1]);
        s.insert(nums[2]);
        if(a + b <= c || b + c <= a || c + a <= b) return "none";
        if(s.size() == 1) return "equilateral";
        else if(s.size() == 2) return "isosceles";
        else return "scalene";
    }
};