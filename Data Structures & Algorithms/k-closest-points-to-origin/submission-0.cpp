class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        vector<vector<int>> res;

        for(auto point : points) {
            int dist_square = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({dist_square, {point[0], point[1]}});
        }

        while(maxHeap.size() > k) {
            maxHeap.pop();
        }

        while(!maxHeap.empty()) {
            auto point = maxHeap.top();
            res.push_back({point.second.first, point.second.second});
            maxHeap.pop();
        }

        return res;
    }
};
