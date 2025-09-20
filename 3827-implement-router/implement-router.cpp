class Router {
public:
    deque<vector<int>> dq;
    unordered_map<int, vector<int>> destTime;
    set<vector<int>> st;
    int m;
    Router(int memoryLimit) {
        m = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(st.find({source, destination, timestamp}) != st.end()) return false;
        if(dq.size() == m) {
            forwardPacket();
        }
        dq.push_back({source, destination, timestamp});
        destTime[destination].push_back(timestamp);
        st.insert({source, destination, timestamp});
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.size() == 0) return {};
        auto t = dq.front();
        dq.pop_front();
        destTime[t[1]].erase(destTime[t[1]].begin());
        st.erase(t);
        return t;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int l = lower_bound(destTime[destination].begin(), destTime[destination].end(), startTime) - destTime[destination].begin();
        if(l >= destTime[destination].size()) return 0;
        int r = upper_bound(destTime[destination].begin(), destTime[destination].end(), endTime) - destTime[destination].begin();
        r--;
        if(r < 0) return 0;
        return r - l + 1;

    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */