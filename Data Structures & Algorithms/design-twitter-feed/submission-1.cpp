class Twitter {
    int count;
    unordered_map<int, vector<pair<int,int>>> tweetMap;  // userId -> [(count, tweetId)]
    unordered_map<int, unordered_set<int>> followMap;    // userId -> {followeeIds}
    
public:
    Twitter() {
        // initialize count
        count = 0;
    }

    void postTweet(int userId, int tweetId) {
        // push (count, tweetId) into tweetMap[userId]
        tweetMap[userId].push_back({count, tweetId});
        count++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int,int>> pq;  // (count, tweetId, userId, index)
        // push last tweet of self + each followee into max heap
        // pop up to 10 times, each time push index-1 of same user back
        // return result
        vector<int> res;
        auto follows = followMap[userId];
        // Need to show the post from user himself
        follows.insert(userId);
        for(int follow : follows) {
            int idx = tweetMap[follow].size() - 1;
            if(idx >= 0){
                auto post = tweetMap[follow].back();
                pq.push({post.first, post.second, follow, idx});
            }
        }

        for(int i = 0; i < 10 && !pq.empty(); i++) {
            // structured binding
            auto [count, tweetId, uid, idx] = pq.top();
            res.push_back(tweetId);
            pq.pop();
            if(idx > 0){
                auto next = tweetMap[uid][idx - 1];
                pq.push({next.first, next.second, uid, idx - 1});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        // add followeeId to followMap[followerId]
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // remove followeeId from followMap[followerId]
        followMap[followerId].erase(followeeId);
    }
};
