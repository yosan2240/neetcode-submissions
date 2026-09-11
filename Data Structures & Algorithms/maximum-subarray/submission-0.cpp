class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

    int maxSubArrayHelper(vector<int>& nums, int left_bound, int right_bound) {
        // Base case: when the input array has only one element
        if(left_bound == right_bound)
            return nums[left_bound];

        // Get the left and right maximum subarray from recursion
        int mid = left_bound + (right_bound - left_bound) / 2;
        int left_max = maxSubArrayHelper(nums, left_bound, mid);
        int right_max = maxSubArrayHelper(nums, mid + 1, right_bound);

        // Get the maximum subarray for the case cross-middle
        int left_sum = nums[mid], right_sum = 0;
        int i = mid - 1, cross_left_max = nums[mid], cross_right_max = 0;
        while(i >= left_bound) {
            left_sum += nums[i];
            cross_left_max = max(cross_left_max, left_sum);
            i--;
        }

        i = mid + 1;
        while(i <= right_bound) {
            right_sum += nums[i];
            cross_right_max = max(cross_right_max, right_sum);
            i++;
        }
        int cross_max = cross_left_max + cross_right_max;

        return max(cross_max, max(left_max, right_max));
    }
};
