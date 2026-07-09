class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> blocks(9);
        int blk_row = 0, blk_col = 0, blk_index = 0;
        

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.')
                    continue;

                blk_row = (i / 3);
                blk_col = (j / 3);
                blk_index = blk_row * 3 + blk_col;
                if (rows[i].count(board[i][j]) || columns[j].count(board[i][j]) ||
                    blocks[blk_index].count(board[i][j])) {
                    return false;
                }
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                blocks[blk_index].insert(board[i][j]);
            }
        }

        return true;
    }
};
