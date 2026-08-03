class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int total = size1 + size2;

        // always binary search on the smaller array to keep mid2 within bounds
        if (size1 > size2) {
            swap(nums1, nums2);
            swap(size1, size2);
        }

        // mid1/mid2 are partition positions, not indices
        // x elements have x+1 valid partition positions
        int l = 0, r = size1;

        // half = number of elements in the left half of the merged array
        int half = (total + 1) / 2;

        while (l <= r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = half - mid1;

            // use INT_MIN/INT_MAX as sentinels when partition is at the boundary
            int maxLeftA  = (mid1 == 0)     ? INT_MIN : nums1[mid1 - 1];
            int minRightA = (mid1 == size1)  ? INT_MAX : nums1[mid1];
            int maxLeftB  = (mid2 == 0)     ? INT_MIN : nums2[mid2 - 1];
            int minRightB = (mid2 == size2)  ? INT_MAX : nums2[mid2];

            if (maxLeftA > minRightB)       // mid1 too far right, move left
                r = mid1 - 1;
            else if (maxLeftB > minRightA)  // mid1 too far left, move right
                l = mid1 + 1;
            else {                          // valid partition found
                if (total % 2)
                    return max(maxLeftA, maxLeftB);
                else
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            }
        }

        return -1;
    }
};