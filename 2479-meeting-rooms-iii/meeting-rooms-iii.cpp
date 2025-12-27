class Solution {
public:
    typedef pair<long long, int> pp;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        set<int> st;
        for(int i = 0; i < n; i++) st.insert(i);
        vector<int> hash(n);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        int idx = 0;
        long long delay = 0;
        for(int i = 0; i < meetings.size(); i++) {
            while(pq.size() && pq.top().first <= meetings[i][0]) {
                auto t = pq.top();
                pq.pop();
                st.insert(t.second);
            }
            if(st.size()) {
                hash[*(st.begin())]++;
                if(hash[idx] < hash[*(st.begin())]) idx = *st.begin();
                else if(hash[idx] == hash[*st.begin()]) idx = min(idx, *st.begin());
                pq.push({meetings[i][1], *st.begin()});
                st.erase(st.begin());
            } else {
                auto t = pq.top();
                pq.pop();
                delay = t.first - meetings[i][0];
                hash[t.second]++;
                if(hash[idx] < hash[t.second]) idx = t.second;
                else if(hash[idx] == hash[t.second]) idx = min(idx, t.second);
                pq.push({1LL * delay + meetings[i][1], t.second});
            }
        }
        return idx;
    }
};