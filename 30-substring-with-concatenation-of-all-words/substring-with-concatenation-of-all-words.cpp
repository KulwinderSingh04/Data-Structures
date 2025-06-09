class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int k = words[0].size();
        unordered_map<string, int> original, use;
        for(int i = 0; i < words.size(); i++) {
            original[words[i]]++;
            use[words[i]]++;
        }
        vector<int> ans;
        int x = words.size();
        for(int i = 0; i < k; i++) {
            int j1 = i;
            int j2 = i;
            use = original;
            while(j2 < s.size()) {
                string str = s.substr(j2, k);
                if(use.find(str) != use.end()) {
                    use[str]--;
                    if(use[str] == 0) use.erase(str);
                    j2 += k;
                    // cout << j2 << " " << j1 << " " << use.size() << endl; 
                    if(use.size() == 0) {
                        ans.push_back(j1);
                        // cout << j1 << " " << j2 << endl;
                    }
                } else {
                    if(original.find(s.substr(j1, k)) != original.end() && original[s.substr(j1, k)] > use[s.substr(j1, k)]) use[s.substr(j1, k)]++;
                    j1 += k;
                }
                if(j1 > j2) j2 = j1;
            }
        }
        return ans;
    }
};