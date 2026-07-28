class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;          // treat the matrix as a flattened 1D array

        while (l <= r) {
            int mid = l + (r - l) / 2;     // avoid integer overflow from (l + r)
            int val = matrix[mid / n][mid % n]; // convert 1D index back to 2D coordinates

            if (val < target) {
                l = mid + 1;               // target is in the right half
            } else if (val > target) {
                r = mid - 1;               // target is in the left half
            } else {
                return true;               // target found
            }
        }

        return false;                      // target not found
    }
};