class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        /* Sort first to reduce it to a 'Two Sum' problem and easily skip duplicate answers.*/
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            /* if the fix value larger than 0 after sorting, it's impossible to get the sum == 0 */
            if (nums[i] > 0)
                break;
            /* Skip the same vlaue for avoiding duplicated answers */
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    /* To skip the duplicated answer */
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
                else if (sum > 0)
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};
