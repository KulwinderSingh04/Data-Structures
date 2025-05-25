class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        int ans = 0;
        for(auto word : words) {
            string a = word;
            swap(a[1], a[0]);
            if(m.find(a) != m.end()) {
                ans += 4;
                m[a]--;
                if(m[a] == 0) m.erase(a);
            } else {
                m[word]++;
            }
        }
        for(auto x : m) {
            if(x.first[0] == x.first[1]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};