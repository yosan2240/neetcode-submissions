class Twitter {
    int count; // Global counter to track tweet order (higher = newer)
    unordered_map<int, vector<pair<int,int>>> tweetMap;  // userId -> [(count, tweetId)]
    unordered_map<int, unordered_set<int>> followMap;    // userId -> {followeeIds}

public:
    Twitter() {
        count = 0;
    }

    void postTweet(int userId, int tweetId) {
        // Store tweet with current count to track recency, then increment counter
        tweetMap[userId].push_back({count, tweetId});
        count++;
    }

    vector<int> getNewsFeed(int userId) {
        // Max heap: (count, tweetId, userId, index in tweet vector)
        priority_queue<tuple<int,int,int,int>> pq;
        vector<int> res;

        // Include the user themselves in the feed
        auto follows = followMap[userId];
        follows.insert(userId);

        // Push the most recent tweet of each followee (and self) into the heap
        for (int follow : follows) {
            if (!tweetMap[follow].empty()) {
                int idx = tweetMap[follow].size() - 1;
                auto [c, tid] = tweetMap[follow][idx];
                pq.push({c, tid, follow, idx});
            }
        }

        // Pop up to 10 most recent tweets
        while (res.size() < 10 && !pq.empty()) {
            auto [c, tweetId, uid, idx] = pq.top();
            pq.pop();
            res.push_back(tweetId);

            // Push the next most recent tweet from the same user
            if (idx > 0) {
                auto [nc, ntid] = tweetMap[uid][idx - 1];
                pq.push({nc, ntid, uid, idx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};