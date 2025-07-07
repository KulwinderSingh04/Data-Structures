class Solution {
public:
    typedef pair<int, int> pp;
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        int i = 0;
        int count = 0;
        int n = events.size();
        for(int d = events[0][0]; d < 1e5 + 1; d++) {
            while(i < n && events[i][0] == d) {
                pq.push({events[i][1], events[i][0]});
                i++;
            }
            while(pq.size() && pq.top().first < d) pq.pop();
            if(pq.size()) {
                count++;
                pq.pop();
            }
        }
        return count;
    }
};