class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        int l = 0, r = size - 1;
        int minimum = INT_MAX;

        //There's no rotation
        if(nums[size - 1] > nums[0])
            return nums[0];

        while(l <= r) {
            // Avoding (l + r) integer overflow
            int mid = l + (r - l) / 2;

            // mid is located in the right half
            if(nums[mid] <= nums[size - 1]){
                r = mid - 1;
                minimum = min(minimum, nums[mid]);
            }
                
            // mid satisfies the drop point condition, let's try
            // if we can push the mid to the right to get maximum value
            else if(nums[mid] > nums[size - 1]){
                l = mid + 1;
            }
        }

        // We need to output the minimum element 
        return minimum;
    }
};
