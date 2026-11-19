class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto check_3_by_3 = [&] (int x, int y) -> bool {
            unordered_set<int> vals;
            for (int i = x; i < x + 3; i++) {
                for (int j = y; j < y + 3; j++) {
                    if (board[i][j] == '.') continue;
                    if (auto s = vals.insert(board[i][j]); !s.second) {
                        return false;
                    }
                }
            }

            return true;
        };

        auto check_row = [&] (int i) -> bool {
            unordered_set<int> vals;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (auto s = vals.insert(board[i][j]); !s.second) {
                    return false;
                }
            }

            return true;
        };

        auto check_col = [&] (int j) -> bool {
            unordered_set<int> vals;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (auto s = vals.insert(board[i][j]); !s.second) {
                    return false;
                }
            }

            return true;
        };

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!check_3_by_3(i,j)) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; ++i) {
            if (!check_row(i)) {
                return false;
            }
        }

        for (int j = 0; j < 9; ++j) {
            if (!check_col(j)) {
                return false;
            }
        }

        return true;
    }
};
