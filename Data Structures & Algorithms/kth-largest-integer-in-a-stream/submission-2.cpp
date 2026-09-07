class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int heapSize;

    // Initialize with k and the initial stream
    // Keep only the k largest elements in the min heap
    KthLargest(int k, vector<int>& nums) {
        heapSize = k;

        for (int num : nums)
            minHeap.push(num);

        // Trim heap to size k, removing smaller elements
        while (minHeap.size() > heapSize)
            minHeap.pop();
    }
    
    // Add a new value and return the kth largest element
    int add(int val) {
        minHeap.push(val);

        // If heap exceeds size k, remove the smallest element
        if (minHeap.size() > heapSize)
            minHeap.pop();

        // Top of min heap is always the kth largest
        return minHeap.top();
    }
};

// Time:  O((n + m) log k) — n for constructor, m calls to add(), each O(log k)
// Space: O(k) — heap maintains at most k elements