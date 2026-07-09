class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int max_amount = 0;

        while (left < right) {
            int width = right - left;
            int height = min(heights[left], heights[right]);
            int amount = width * height;
            max_amount = max(max_amount, amount);
            if(heights[left] >= heights[right])
                right--;
            else
                left++;
        }

        return max_amount;
    }
};
