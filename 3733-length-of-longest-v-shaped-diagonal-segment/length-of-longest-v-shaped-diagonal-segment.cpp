class Solution {
public:

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int dp[n][m][4][2];
        memset(dp, -1, sizeof dp);

        // x, y, dir, turn
        function<int(int, int, int, int, int)> dfs = [&] (int x, int y, int dir, int turn, int value) -> int
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != value)
            {
                return 0;
            }

            int &ret = dp[nx][ny][dir][turn];
            if (ret != -1) return ret;

            ret = dfs(nx, ny, dir, turn, 2 - value) + 1;

            if (turn == 0)
            {
                ret = max(ret, 1 + dfs(nx, ny, (dir + 1) % 4, 1, 2 - value));
            }

            return ret;
        };

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int result = dfs(i, j, d, 0, 2);
                        ans = max(ans, result + 1);
                    }
                }
            }
        }

        return ans;
    }
};