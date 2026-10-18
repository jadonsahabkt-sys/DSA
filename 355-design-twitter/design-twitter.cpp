class Twitter {
    int timer =0;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
       tweets[userId].push_back({timer++,tweetId});    
    }

    
    vector<int> getNewsFeed(int userId) {
        priority_queue<array<int,4>> pq;
        following[userId].insert(userId);
        for(int f: following[userId]){
            auto it =tweets.find(f);
            if(it==tweets.end() || it->second.empty()) continue;
            int idx=it->second.size()-1;
            pq.push({it->second[idx].first,it->second[idx].second,f,idx}); 
        }
        vector<int> res;
        while(!pq.empty() && res.size() < 10){
            auto[t,tid,u,idx]=pq.top();
            pq.pop();
            res.push_back(tid);
            if(idx>0){
                auto& p=tweets[u][idx-1];
                pq.push({p.first,p.second,u,idx-1});
            }
        }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].erase(followeeId);    
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