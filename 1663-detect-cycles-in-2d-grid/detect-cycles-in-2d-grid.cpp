class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int pr, int pc, char target) {
        visited[r][c] = true;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==target){
                if (nr == pr && nc == pc) continue;
                if (visited[nr][nc]) return true;
                if (dfs(grid, visited, nr, nc, r, c, target)) return true;
            }
        }
        return false;
    }
};
