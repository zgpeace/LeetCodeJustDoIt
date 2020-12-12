class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        r = grid.size(), c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    int d[5] = {0, 1, 0, -1, 0};
    int res = 0, r, c;

    void dfs(vector<vector<char>>& grid, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                dfs(grid, nx, ny);
            }
        }
    }
};