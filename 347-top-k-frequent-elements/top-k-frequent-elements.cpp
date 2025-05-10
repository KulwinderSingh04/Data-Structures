class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto x:m) {
            pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()) {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};