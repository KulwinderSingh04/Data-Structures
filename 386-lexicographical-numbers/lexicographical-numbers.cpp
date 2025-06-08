class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> a;
        for(int i = 1; i < n + 1; i++) {
            a.push_back(to_string(i));
        }
        sort(a.begin(), a.end());
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(stoi(a[i]));
        }
        return ans;
    }
};