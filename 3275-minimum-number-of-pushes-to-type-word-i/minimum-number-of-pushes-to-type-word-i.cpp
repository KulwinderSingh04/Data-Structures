class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int one = 8;
        int two = 8;
        int three = 8;
        int four = 8;
        int ans = 0;
        vector<int> hash(26);
        unordered_map<int, int> mp;
        for(auto x : word) mp[x]++;
        priority_queue<pair<int, char>> pq;
        for(auto x : mp) pq.push({x.second, x.first});
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int freq = t.first;
            char ch = t.second;
            if(hash[ch - 'a'] == 0) {
                if(one) {
                    hash[ch - 'a'] = 1;
                    one--;
                } else if(two) {
                    hash[ch - 'a'] = 2;
                    two--;
                } else if(three) {
                    hash[ch - 'a'] = 3;
                    three--;
                } else {
                    hash[ch - 'a'] = 4;
                    four--;
                }
            }
            ans += hash[ch - 'a'] * freq;
        }
        return ans;
    }
};