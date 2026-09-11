class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kick off the divide and conquer over the entire array
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

    int maxSubArrayHelper(vector<int>& nums, int left_bound, int right_bound) {
        // Base case: only one element, it is its own maximum subarray
        if (left_bound == right_bound)
            return nums[left_bound];

        // Divide: find the midpoint (safe formula avoids integer overflow)
        int mid = left_bound + (right_bound - left_bound) / 2;

        // Conquer: recursively get the best subarray in each half
        int left_max = maxSubArrayHelper(nums, left_bound, mid);
        int right_max = maxSubArrayHelper(nums, mid + 1, right_bound);

        // --- Cross-middle case ---
        // The cross subarray must include nums[mid], so we start both scans from mid.

        // Scan leftward from mid, tracking the best prefix sum ending at mid
        int left_sum = nums[mid];
        int cross_left_max = nums[mid]; // initialized to nums[mid] since mid is always included
        for (int i = mid - 1; i >= left_bound; i--) {
            left_sum += nums[i];
            cross_left_max = max(cross_left_max, left_sum);
        }

        // Scan rightward from mid+1, tracking the best suffix sum starting just after mid
        int right_sum = 0;
        int cross_right_max = 0; // initialized to 0 since the right side may contribute nothing
        for (int i = mid + 1; i <= right_bound; i++) {
            right_sum += nums[i];
            cross_right_max = max(cross_right_max, right_sum);
        }

        // Combine: the cross-middle maximum is the sum of both sides
        int cross_max = cross_left_max + cross_right_max;

        // Return the best among all three cases
        return max(cross_max, max(left_max, right_max));
    }
};