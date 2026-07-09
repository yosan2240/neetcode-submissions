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
// Brute force checks every pair of bars, but we can prove a key
// property: once we fix pointers `left` and `right` and compute
// the area between them, keeping the taller pointer fixed and
// shrinking the width from the shorter side never helps.
//
// Specifically, if height[left] < height[right], then for any
// index j strictly between them, the area of (left, j) is bounded
// by (j - left) * height[left], which is strictly less than
// (right - left) * height[left], the area of (left, right).
// This holds because min(height[left], height[j]) can never
// exceed height[left], and the width (j - left) is always
// smaller than (right - left).
//
// So every pairing that keeps `left` fixed and picks some j
// before `right` is dominated by the pair (left, right) already
// evaluated -- no need to check them again.
//
// This means the only way to potentially find a better area is
// to move the pointer at the SHORTER bar inward, since that's
// the one limiting the height, and its pairings with everything
// up to the other pointer are already proven no better than the
// current result. Moving the taller pointer instead only shrinks
// the width while the height stays capped at the same (or lower)
// limiting value, so it can only decrease or match the area,
// never improve it.
//
// Tie case (height[left] == height[right]): the same domination
// argument applies symmetrically in either direction, so it does
// not matter which pointer (or both) is advanced.
//
// Algorithm: start pointers at both ends, repeatedly compute the
// area, update the best result seen so far, and move the pointer
// at the shorter bar inward, until the pointers meet.
