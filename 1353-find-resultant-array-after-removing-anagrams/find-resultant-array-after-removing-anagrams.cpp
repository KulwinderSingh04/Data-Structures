class Solution {
public:
    bool isAnagram(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i = 1; i < n; i++) {
            if(!isAnagram(words[i], words[i - 1])) ans.push_back(words[i]);
        }
        return ans;
    }
};