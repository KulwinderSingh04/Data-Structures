class Twitter {
public:
    map<int, set<int>> m;
    map<int, vector<pair<int, int>>> tweet;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time--, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> v;
        for(auto x : m[userId]) {

            for(auto t : tweet[x]) {
                v.push_back(t);
            }
        }

        for(auto t : tweet[userId]) {
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = 0; i < min((int)v.size(), 10); i++) {
            cout << v[i].first << " ";
            ans.push_back(v[i].second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(m[followerId].find(followeeId) != m[followerId].end()) m[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */