class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row/col

        for (int i = 0; i<9; i++) {
            vector<char> col;
            vector<char> row;
            for (int j = 0; j<9; j++) {
                if (board[i][j] != '.') {
                    row.push_back(board[i][j]);
                }
                if (board[j][i] != '.') {
                    col.push_back(board[j][i]);
                }
                if (row.size() != unordered_set<char> (row.begin(), row.end()).size()
                || col.size() != unordered_set<char> (col.begin(), col.end()).size()) {
                    return false;
                }
            }
        }
        // square
        for (int start = 0; start<9; start++) {
            // start point each square: 00 03 06 30 33 36 60 63 66
            vector<char> squ;
            for (int i = 3*(start/3); i<3*(start/3)+3; i++) {
                for (int j = 3*(start%3) ; j<3*(start%3)+3; j++) {
                    if (board[i][j] != '.') {
                        squ.push_back(board[i][j]);
                    }
                    if (squ.size() != unordered_set<char> (squ.begin(), squ.end()).size()) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
