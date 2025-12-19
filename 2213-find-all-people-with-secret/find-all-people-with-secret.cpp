class Solution {
public:
    typedef pair<int, int> pp;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        vector<vector<pp>> adj(n);
        for(auto x: meetings) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        priority_queue<pp, vector<pp>, greater<pp>> q;
        q.push({0, 0});
        q.push({0, firstPerson});
        unordered_set<int> st;
        st.insert(0);
        st.insert(firstPerson);
        vector<int> timeArr(n, INT_MAX);
        timeArr[0] = 0;
        timeArr[firstPerson] = 0;
        while(q.size()) {
            auto t = q.top();
            q.pop();
            int node = t.second;
            int time = t.first;
            for(auto x : adj[node]) {
                if(x.second >= timeArr[x.first]) continue;
                if(time <= x.second) {
                    st.insert(x.first);
                    timeArr[x.first] = x.second;
                    q.push({x.second, x.first});
                }
            }
        }
        vector<int> ans;
        for(auto x : st) ans.push_back(x);
        return ans;
    }
};