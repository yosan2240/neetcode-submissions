class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        // Monotonic decreasing deque — stores indices, front is always the max of current window
        deque<int> dq;

        // Initialize deque for the first window [0, k-1]
        for (int i = 0; i < k; i++) {
            // Remove from back any elements smaller than nums[i] —
            // they can never be the max while nums[i] is in the window
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]); // max of first window

        // Slide the window one step at a time
        for (int l = 1, r = l + k - 1; r < nums.size(); l++, r++) {
            // Remove front if it's no longer inside the window
            if (dq.front() < l)
                dq.pop_front();

            // Maintain decreasing order — discard useless smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();
            dq.push_back(r);

            // Front of deque is always the max of current window
            result.push_back(nums[dq.front()]);
        }

        return result;
    }
};