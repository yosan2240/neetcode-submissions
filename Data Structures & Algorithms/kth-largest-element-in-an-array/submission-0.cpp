class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Use min-heap to extract the largest k numbers
        for(int num : nums) {
            minHeap.push(num);
            if(minHeap.size() > k)
                minHeap.pop();
        }


        return minHeap.top();
    }
};
