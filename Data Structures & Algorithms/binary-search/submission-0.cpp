class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2; //Avoid integer overflow
            if(target < nums[mid]) {
                r = mid - 1;
            }
            else if (target > nums[mid]) {
                l = mid + 1;
            }
            else
                return mid;
        }

        return -1;
    }
};
