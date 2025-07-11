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
            if(roomHeap.size()) {
                endTimeHeap.push({meetings[i][1], roomHeap.top()});
                rooms[roomHeap.top()]++;
                roomHeap.pop();
            } else {
                auto t = endTimeHeap.top();
                endTimeHeap.pop();
                long long roomAvailable = t.second;
                long long meetFinish = t.first;
                rooms[roomAvailable]++;
                if(meetings[i][0] < meetFinish) endTimeHeap.push({1LL * meetings[i][1] + (meetFinish - meetings[i][0]), roomAvailable});
                else endTimeHeap.push({meetings[i][1], roomAvailable});
            }
            // cout << i << endl;
            while(i < meetings.size() - 1 && endTimeHeap.size() && endTimeHeap.top().first <= meetings[i + 1][0]) {
                // cout << endTimeHeap.top().second << " ";
                roomHeap.push(endTimeHeap.top().second);
                endTimeHeap.pop();
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) if(rooms[i] > rooms[ans]) ans = i;
        return ans;
    }
};