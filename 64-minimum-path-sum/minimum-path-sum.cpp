class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        for(int i = row-1; i>=0; i--) {
            for(int j  = col-1; j>=0; j--) {
                if(i == row-1 && j == col-1) continue;
                if(i == row-1) {
                    grid[i][j] += grid[i][j+1];
                }
                else if(j == col-1) {
                    grid[i][j] += grid[i+1][j];
                }
                else {
                    grid[i][j] += min(grid[i][j+1], grid[i+1][j]);
                }
            }
        }
        return grid[0][0];
    }
};