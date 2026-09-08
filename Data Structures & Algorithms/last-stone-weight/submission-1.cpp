class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Build max-heap from all stones
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        // Keep smashing the two heaviest stones
        while (maxHeap.size() >= 2) {
            int stone1 = maxHeap.top(); maxHeap.pop();  // heaviest
            int stone2 = maxHeap.top(); maxHeap.pop();  // second heaviest

            // If stones are not equal, push the remaining weight back
            int res = stone1 - stone2;
            if (res)
                maxHeap.push(res);
        }

        // Return last stone weight, or 0 if no stones remain
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

// Time:  O(n log n) — at most n rounds, each O(log n) heap operations
// Space: O(n) — heap stores all stones