class Solution {
public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
      
        for (int startRow = n - 2; startRow >= 0; --startRow) {
            int i = startRow, j = 0;
            std::vector<int> diagonalElements;
            while (i < n && j < n) {
                diagonalElements.push_back(grid[i][j]);
                i++;
                j++;
            }
            std::sort(diagonalElements.begin(), diagonalElements.end());
            for (int element : diagonalElements) {
                i--;
                j--;
                grid[i][j] = element;
            }
        }
      
        for (int startCol = n - 2; startCol > 0; --startCol) {
            int i = startCol, j = n - 1;
            std::vector<int> diagonalElements;
            while (i >= 0 && j >= 0) {
                diagonalElements.push_back(grid[i][j]);
                i--;
                j--;
            }
            std::sort(diagonalElements.begin(), diagonalElements.end());
            for (int element : diagonalElements) {
                i++;
                j++;
                grid[i][j] = element;
            }
        }
      
        return grid;
    }
};
