class Solution {
public:
    int trap(vector<int>& height) {
        /* Time: O(n), Space: O(1) */
        int result = 0;
        int left = 0, right = height.size() - 1;

        // Running max from each side — replaces the precomputed arrays
        int leftMax = 0, rightMax = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                // leftMax is the bottleneck — water level at `left` is determined by leftMax
                // (we don't need to know the exact rightMax, just that it's >= height[left])
                leftMax = max(leftMax, height[left]);
                result += leftMax - height[left]; // always >= 0 since leftMax >= height[left]
                left++;
            } else {
                // rightMax is the bottleneck — symmetric case
                rightMax = max(rightMax, height[right]);
                result += rightMax - height[right]; // always >= 0 since rightMax >= height[right]
                right--;
            }
        }

        return result;
    }
};