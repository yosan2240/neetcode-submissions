class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = matrix[mid / n][mid % n];

            if (val < target) {
                l = mid + 1;
            } else if (val > target) {
                r = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
