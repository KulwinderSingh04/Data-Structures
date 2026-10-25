class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        vector<vector<int>> vec(n, vector<int> (n, 0));
        vector<unordered_map<int, int>> freq(n);
        for(int i = 0; i < n; i++) {
            unordered_set<int> st; 
            for(int j = i; j < n; j++) {
                st.insert(s[j]);
                vec[i][j] = st.size();
                freq[i][vec[i][j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int val = vec[i][j];
                if(j + 1 < n) ans += freq[j + 1][val];
            }
        }
        return ans;
    }
};