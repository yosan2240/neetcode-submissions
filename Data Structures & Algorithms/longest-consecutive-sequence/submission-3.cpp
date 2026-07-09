class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 1, longest_count = 0, old = 0;
        if (nums.size() <= 1) 
            return nums.size();
        sort(nums.begin(), nums.end());
        old = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == old)
                continue;
            if (nums[i] == old + 1) {
                count++;   
            } 
            else {   
                count = 1;
            }
            old = nums[i];
            longest_count = max(count, longest_count);
        }
        longest_count = max(count, longest_count);
        
        return longest_count;
    }
};
