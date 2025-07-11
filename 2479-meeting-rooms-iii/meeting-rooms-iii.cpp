class Solution {
public:
    typedef pair<long long, long long> pp;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> rooms(n, 0);
        priority_queue<long long, vector<long long>, greater<long long>> roomHeap;
        priority_queue<pp, vector<pp>, greater<pp>> endTimeHeap;
        for(int i = 0; i < n; i++) roomHeap.push(i);
        sort(meetings.begin(), meetings.end());
        for(int i = 0; i < meetings.size(); i++) {
            while(endTimeHeap.size() && endTimeHeap.top().first <= meetings[i][0]) {
                // cout << endTimeHeap.top().second << " ";
                roomHeap.push(endTimeHeap.top().second);
                endTimeHeap.pop();
            }
            if(roomHeap.size()) {
                int room = roomHeap.top();
                roomHeap.pop();
                rooms[room]++;
                endTimeHeap.push({meetings[i][1], room});
            } else {
                auto t = endTimeHeap.top();
                endTimeHeap.pop();
                long long roomAvailable = t.second;
                long long meetFinish = t.first;
                rooms[roomAvailable]++;
                long long duration = 1LL * meetings[i][1] - meetings[i][0];
                endTimeHeap.push({meetFinish + duration, roomAvailable});
            }
            // cout << i << endl;
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) if(rooms[i] > rooms[ans]) ans = i;
        return ans;
    }
};