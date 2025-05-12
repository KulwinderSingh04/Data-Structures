class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> m;
        for(auto digit : digits) {
            m[digit]++;
        }
        vector<int> ans;
        for(int i = 100; i < 1000; i++) {
            if(i % 2 == 1) continue;
            string str = to_string(i);
            if(m.find(str[0] - 48) != m.end()) {
                m[str[0] - 48]--;
                if(m[str[0] - 48] == 0) m.erase(str[0] - 48);
                if(m.find(str[1] - 48) != m.end()) {
                    m[str[1] - 48]--;
                    if(m[str[1] - 48] == 0) m.erase(str[1] - 48);
                    if(m.find(str[2] - 48) != m.end()) {
                        ans.push_back(i);
                    }
                    m[str[1] - 48]++;
                }
                m[str[0] - 48]++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};