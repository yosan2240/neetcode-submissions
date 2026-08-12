class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        // phase 1: detect cycle
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // phase 2: find cycle entry point (the duplicate)
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
