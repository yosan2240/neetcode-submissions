class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int heapSize;

    KthLargest(int k, vector<int>& nums) {
        heapSize = k;

        for(int num : nums) 
            minHeap.push(num);

        while(minHeap.size() > heapSize)
            minHeap.pop();
    }
    
    int add(int val) {
        int res;
        minHeap.push(val);
        if(minHeap.size() > heapSize)
            minHeap.pop();

        return minHeap.top();
    }
};
