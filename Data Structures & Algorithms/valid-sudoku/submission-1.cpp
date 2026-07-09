class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Track seen digits for each row, column, and 3x3 block
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> blocks(9);
        int blk_row = 0, blk_col = 0, blk_index = 0;
        

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Skip empty cells
                if (board[i][j] == '.')
                    continue;
                // Map (i, j) to its 3x3 block index (0~8)
                blk_row = (i / 3);
                blk_col = (j / 3);
                blk_index = blk_row * 3 + blk_col;
                // If digit already seen in same row, column, or block → invalid
                if (rows[i].count(board[i][j]) || columns[j].count(board[i][j]) ||
                    blocks[blk_index].count(board[i][j])) {
                    return false;
                }
                // Mark digit as seen
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                blocks[blk_index].insert(board[i][j]);
            }
        }

        return true;
    }
};
