class Solution {
public:
    // Floyd's Cycle Detection applied to find duplicate:
    // treat array values as pointers: index i -> index nums[i]
    // duplicate creates a cycle; the cycle entry point = duplicate number
    //
    // proof that phase 2 finds the entry point:
    //   let F = distance from start to cycle entry
    //       C = cycle length
    //       h = distance from entry to meeting point
    //       k = number of full cycles fast completed before meeting slow
    //   at phase 1 meeting point:
    //       slow traveled: F + h
    //       fast traveled: F + h + k*C (k >= 1)
    //       since fast = 2 * slow: F + h + k*C = 2(F + h)
    //       => F = k*C - h
    //   so slow2 (from start) travels F steps to reach entry point
    //   fast (from meeting point) travels k*C - h steps
    //   = k full cycles minus h = also lands on entry point
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