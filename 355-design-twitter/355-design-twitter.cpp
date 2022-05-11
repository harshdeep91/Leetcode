class Twitter {
  unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, set<int>> followers;
    int count=0;

public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, pair<int,int>>> q;
        if(tweets[userId].size())
                q.push({tweets[userId].back().first, {tweets[userId].size()-1,userId}});
        for(auto x:followers[userId])
        {
            if(tweets[x].size())
                q.push({tweets[x].back().first, {tweets[x].size()-1,x}});
        }
        vector<int> ans;
        while(!q.empty()&&ans.size()<10)
        {
            int order = q.top().first;
            int i = q.top().second.first;
            int userIds = q.top().second.second;
            ans.push_back(tweets[userIds][i--].second);
            q.pop();
            if (i >= 0)
                q.push({tweets[userIds][i].first, {i, userIds}});
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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