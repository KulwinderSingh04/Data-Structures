class TaskManager {
public:
    typedef pair<int, int> pp;
    unordered_map<int, pp> taskToUser;
    set<vector<int>> taskManager;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto x : tasks) {
            taskToUser[x[1]] = {x[0], x[2]};
            taskManager.insert({-x[2], -x[1], x[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToUser[taskId] = {userId, priority};
        taskManager.insert({-priority, -taskId, userId});
        // if(taskManager.find({-8, -101, 50}) != taskManager.end()) cout<< "yes" <<" ";
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskToUser[taskId].first;
        int priority = taskToUser[taskId].second;
        taskToUser[taskId].second = newPriority;
        taskManager.erase({-priority, -taskId, userId});
        taskManager.insert({-newPriority, -taskId, userId});
    }
    
    void rmv(int taskId) {
        int userId = taskToUser[taskId].first;
        int priority = taskToUser[taskId].second;
        taskManager.erase({-priority, -taskId, userId});
        taskToUser.erase(taskId);
    }
    
    int execTop() {
        if(taskManager.size() == 0) return -1;
        // cout << "hell" << " ";
        // if(taskManager.find({-8, -101, 50}) != taskManager.end()) cout<< "yes" <<" ";
        const vector<int>& arr = (*taskManager.begin());
        int ans = arr[2];
        int id = -arr[1];
        rmv(id);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */