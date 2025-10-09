class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> arr(n);
        arr[0] = skill[0] * mana[0];
        for(int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + 1LL * skill[i] * mana[0];
        }
        for(int i = 1; i < m; i++) {
            arr[0] += skill[0] * mana[i];
            for(int j = 1; j < n; j++) {
                arr[j] = max(arr[j], arr[j - 1]) + 1LL * skill[j] * mana[i];
            }
            for(int j = n - 1; j > 0; j--) {
                arr[j - 1] = arr[j] - skill[j] * 1LL * mana[i];
            }
        }
        return arr[n - 1];
    }
};