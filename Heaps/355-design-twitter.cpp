class Twitter {
public:
    int time = 1;
    vector<priority_queue<pair<int, int>>> feeds{501};
    vector<set<int>> followers{501};
    vector<vector<pair<int, int>>> self_tweets{501};
    unordered_map<int, int> map;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        self_tweets[userId].push_back({time, tweetId});
        map[tweetId] = userId;
        feeds[userId].push({time, tweetId});
        set<int> list = followers[userId];
        for(auto &user:list) {
            feeds[user].push({time, tweetId});
        }
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto p = feeds[userId];
        while(!p.empty() and res.size() < 10) {
            int tweetId = p.top().second; p.pop();
            if(followers[map[tweetId]].count(userId) or (map[tweetId] == userId))
                res.push_back(tweetId);
            
        }
        // assert(res.size() == 10);
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followers[followeeId].count(followerId)) return;
        followers[followeeId].insert(followerId);
        auto vec = self_tweets[followeeId];
        for(auto &tweet:vec) {
            feeds[followerId].push(tweet);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followeeId].erase(followerId);
    }
};
