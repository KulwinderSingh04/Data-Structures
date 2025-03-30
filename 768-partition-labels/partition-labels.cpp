class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        for(int i = 0; i < n; i++) m[s[i]]++;
        unordered_map<char, int> t;
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(j < n) {
            t[s[j]]++;
            if(t[s[j]] == m[s[j]]) t.erase(s[j]);
            if(t.size() == 0) {
                ans.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }
        return ans;
    }
};