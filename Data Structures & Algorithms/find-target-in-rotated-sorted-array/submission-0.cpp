class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;
            // Check which half is sorted
            // The left half is completely sorted
            if(nums[mid] >= nums[l]) {
                if(target >= nums[l] && target < nums[mid]) {
                    r = mid - 1; 
                }
                // The target is not in the range [l, mid]
                else {
                    l = mid + 1;
                }
            }
            // The right half is completely sorted
            else{
                if(target <= nums[r] && target > nums[mid]) {
                    l = mid + 1; 
                }
                // The target is not in the range [l, mid]
                else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};
