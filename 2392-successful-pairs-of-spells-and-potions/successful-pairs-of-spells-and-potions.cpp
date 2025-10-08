class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int idx = upper_bound(potions.begin(), potions.end(), (success % spells[i] ? success / spells[i] : success / spells[i] - 1)) - potions.begin();
            ans.push_back(potions.size() - idx);
        }
        return ans;
    }
};