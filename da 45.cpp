class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        auto dfs = [&](auto& self, int r, int c) -> void {
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') {
                return;
            }
            grid[r][c] = '0';
            self(self, r + 1, c);
            self(self, r - 1, c);
            self(self, r, c + 1);
            self(self, r, c - 1);
        };

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    ++islands;
                    dfs(dfs, r, c);
                }
            }
        }

        return islands;
    }
};
