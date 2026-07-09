class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> table;
        // initialize result with 0 so we don't need to check if nums is empty
        int result = 0;

        for (int& num : nums) {
            table.insert(num);
        }

        for (int num : table) {
            // 不是起點，跳過
            if (table.count(num - 1))
                continue;  
            int count = 1;
            while (table.count(num + 1)){
                count++;
                num++;
            }
            result = max(result, count);
        }
        return result;
    }
};

/*
Hash Set 解法思路：

1. 把所有數字存進 unordered_set，讓查找變 O(1)

2. 遍歷每個數字，只從「序列起點」開始計數
   - 起點定義：num-1 不在 set 裡（前面沒有人）
   - 非起點直接 continue，避免重複計算

3. 從起點開始，不斷往上檢查 num+1 是否在 set 裡
   - 在的話 count++，繼續往上
   - 不在的話停止，更新 result

4. 為什麼是 O(n)？
   - 每個數字只會在「自己序列的起點被找到時」被往上數到一次
   - 非起點直接跳過，不重複計算
*/