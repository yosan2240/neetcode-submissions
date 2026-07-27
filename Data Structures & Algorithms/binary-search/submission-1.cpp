class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size - 1;

        while (l <= r) {                        // empty range when l > r
            int mid = l + (r - l) / 2;         // avoid integer overflow from (l + r)
            if (target < nums[mid]) {
                r = mid - 1;                    // target is in the left half
            } else if (target > nums[mid]) {
                l = mid + 1;                    // target is in the right half
            } else {
                return mid;                     // target found
            }
        }

        return -1;                              // target not found
    }
};