class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        
        int count = 1, longest = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) continue;       // skip duplicates
            if (nums[i] == nums[i-1] + 1) count++;    // consecutive
            else count = 1;                            // reset
            longest = max(longest, count);
        }
        
        return longest;
    }
};