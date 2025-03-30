class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> hash(26, -1);
        for(int i = n - 1; i >= 0; i--) if(hash[s[i] - 97] == -1) hash[s[i] - 97] = i;
        int i = 0;
        int j = 0;
        int end = 0;
        vector<int> ans;
        while(j < n) {
            if(end < hash[s[j] - 97]) end = hash[s[j] - 97];
            if(end == j) {
                ans.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }
        return ans;
    }
};