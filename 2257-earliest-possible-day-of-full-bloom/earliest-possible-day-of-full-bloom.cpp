class Solution {
public:
    typedef pair<int, int> pp;
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue<pp> pq;
        int n = plantTime.size();
        for(int i = 0; i < n; i++) {
            pq.push({growTime[i], plantTime[i]});
        }
        int time = 0;
        int ans = 0;
        while(pq.size()) {
            auto t = pq.top();
            // cout << t.first << " " << t.second << " " << time << endl;
            pq.pop();
            time += t.second;

            ans = max(time + t.first, ans);
        }
        return ans;
    }
};