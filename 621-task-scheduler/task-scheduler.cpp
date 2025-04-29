class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        k++;
        vector<int> hash(26);
        for(int i = 0; i < n; i++) {
            hash[tasks[i] - 65]++;
        }
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++) {
            if(hash[i] != 0) pq.push(hash[i]);
        }
        int count = 0;
        while(pq.size()) {
            vector<int> v;
            int sz = pq.size();
            for(int i = 0; i < min(k, sz); i++) {
                auto t = pq.top();
                count++;
                pq.pop();
                if(t - 1 > 0) v.push_back(t - 1);
            }
            if(k - sz > 0 && v.size()) {
                count += k - sz;
            }
            for(int i = 0; i < v.size(); i++) pq.push(v[i]);
        }
        return count;
    }
};