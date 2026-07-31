class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        int l = 0, r = size - 1;
        int minimum = INT_MAX;

        /* Even if the array isn't rotated, the binary search algorithm can handle it */
        while(l <= r) {
            // avoid integer overflow from (l + r)
            int mid = l + (r - l) / 2;

            // mid is in the right half, record as minimum candidate and search left
            if(nums[mid] <= nums[size - 1]){
                r = mid - 1;
                minimum = min(minimum, nums[mid]);
            }
            // mid is in the left half, search right to find the drop point
            else {
                l = mid + 1;
            }
        }

        return minimum;
    }
};