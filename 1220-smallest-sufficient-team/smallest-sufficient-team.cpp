class Solution {
public:
    vector<int> res;
    int targetMask;
    unordered_map<string, int> dp;
    void fun(int i, int mask, vector<int>& skills, vector<int>& temp) {
        int n = skills.size();
        if(i == n) {
            if(mask == targetMask) {
                if(res.size() == 0 || res.size() > temp.size()) res = temp;
            }
            return;
        }
        string str = to_string(i) + '_' + to_string(mask);
        if(dp.find(str) != dp.end()) {
            if(dp[str] <= temp.size()) return;
        }
        fun(i + 1, mask, skills, temp);

        if((mask | skills[i]) == mask) return;
        temp.push_back(i);
        fun(i + 1, mask | skills[i], skills, temp);
        temp.pop_back();
        dp[str] = temp.size() != 0 ? temp.size(): -1; 
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        targetMask = ((1 << n) - 1);
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            mp[req_skills[i]] = i;
        }
        vector<int> skills;
        for(auto x : people) {
            int bitOr = 0;
            for(auto y : x) {
                bitOr |= (1 << mp[y]);
            }
            skills.push_back(bitOr);
        }
        vector<int> temp;
        fun(0, 0, skills, temp);
        return res;
    }
};