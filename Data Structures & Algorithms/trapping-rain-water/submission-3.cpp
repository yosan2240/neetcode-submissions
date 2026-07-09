class Solution {
public:
    int trap(vector<int>& height) {
        /* Time: O(n), Space: O(1)*/
        int result = 0;
        int leftmax = 0, rightmax = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftmax = max(leftmax, height[left]);
                if (leftmax - height[left] > 0)
                    result += leftmax - height[left];
                left++;
            }
            else {
                rightmax = max(rightmax, height[right]);
                if (rightmax - height[right] > 0)
                    result += rightmax - height[right];
                right--;
            }                
        }

        return result;
    }
};
