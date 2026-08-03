class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int total = nums1.size() + nums2.size();
        if (size1 > size2) {
            swap(nums1, nums2);
            swap(size1, size2);
        }
        // mid is not the index of an element, but the index of a partition
        // so x elements have x + 1 positions to place the partition
        int l = 0, r = size1;
        // half represents the number of elements partitioned by the median
        int half = (total + 1) / 2;

        while(l <= r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = half - mid1;
            int maxLeftA  = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
            int minRightA = (mid1 == size1) ? INT_MAX : nums1[mid1];
            int maxLeftB  = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            int minRightB = (mid2 == size2) ? INT_MAX : nums2[mid2];

            if(maxLeftA > minRightB)
                r = mid1 - 1;
            else if(maxLeftB > minRightA)
                l = mid1 + 1;
            else{
                if(total % 2)  
                    return max(maxLeftA, maxLeftB);
                else  
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            } 
        }

        return -1;
    }
};