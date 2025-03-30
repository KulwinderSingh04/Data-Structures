class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> hash(26, -1);
        for(int i = n - 1; i >= 0; i--) if(hash[s[i] - 97] == -1) hash[s[i] - 97] = i;
        set<char> t;
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(j < n) {
            t.insert(s[j]);
            if(hash[s[j] - 97] == j) t.erase(s[j]);
            if(t.size() == 0) {
                ans.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }
        return ans;
    }
};