class Solution {
public:
    priority_queue<int> maxHeap;
    int lastStoneWeight(vector<int>& stones) {
        for(int stone : stones) {
            maxHeap.push(stone);
        }

        while(maxHeap.size() >= 2) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();

            int res = stone1 - stone2;
            if(res)
                maxHeap.push(res);
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
