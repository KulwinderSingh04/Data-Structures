class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1;
        int n = edges.size();
        vector<int> v1(n, -1), v2(n, -1);
        int node = node1;
        int time = 0;
        vector<int> vis1(n), vis2(n);
        while(node != -1 && vis1[node] == 0) {
            v1[node] = time;
            time++;
            vis1[node] = 1;
            node = edges[node];
        }

        node = node2;
        time = 0;
        while(node != -1 && vis2[node] == 0) {
            v2[node] = time;
            time++;
            vis2[node] = 1;
            node = edges[node];
        }
        int ans = INT_MAX, idx = -1;
        for(int i = 0; i < n; i++) {
            if(v1[i] == -1 || v2[i] == -1) continue;
            if(ans > max(v1[i], v2[i])) {
                ans = max(v1[i], v2[i]);
                idx = i;
            }
        }
        return idx;
    }
};