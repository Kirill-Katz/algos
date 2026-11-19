class Solution {
public:

    void solve(vector<vector<char>>& board) {
        int n = (int)board.size();
        int m = (int)board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        auto dfs = [&](auto&& self, int i, int j, vector<pair<int,int>>& region) -> bool {
            if (vis[i][j]) {
                return false;
            }

            vis[i][j] = true;

            if (board[i][j] == 'X') {
                return false;
            } else {
                region.push_back({i, j});
            }

            bool ans = (i == 0) || (j == 0) || (i == n - 1) || (j == m - 1);

            if (i - 1 >= 0) {
                ans = self(self, i - 1, j, region) || ans;
            }

            if (j - 1 >= 0) {
                ans = self(self, i, j - 1, region) || ans;
            }

            if (i + 1 < n) {
                ans = self(self, i + 1, j, region) || ans;
            }

            if (j + 1 < m) {
                ans = self(self, i, j + 1, region) || ans;
            }

            return ans;
        };

        auto change = [&](vector<pair<int,int>>& region) {
            for (auto [i, j] : region) {
                board[i][j] = 'X';
            }
        };

        vector<pair<int,int>> region;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool keep = dfs(dfs, i, j, region);

                if (!keep) {
                    change(region);
                }

                region.clear();
            }
        }
    }
};
