class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> table;
        int result = 1, count = 1;

        for (int& num : nums) {
            table.insert(num);
        }


        for (int num : table) {
            // 不是起點，跳過
            if (table.count(num - 1))
                continue;  
            while (table.count(num + 1)){
                count++;
                num++;
            }
            result = max(result, count);
            count = 1;
        }
        return result;
    }
};