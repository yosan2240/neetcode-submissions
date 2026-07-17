class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        /* Initialize the deque */
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);

        for(int l = 1, r = l + k - 1; r < nums.size(); l++, r++) {
            if(dq.front() < l)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            /* push the maximum element within window to result */
            result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
