class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> width(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 1) {
                    width[row][col] = col == 0 ? 1 : 1 + width[row][col - 1];
                }
            }
        }

        int totalCount = 0;

        for (int topRow = 0; topRow < rows; ++topRow) {
            for (int col = 0; col < cols; ++col) {
                int minWidth = INT_MAX;
                for (int bottomRow = topRow; bottomRow >= 0 && minWidth > 0; --bottomRow) {
                    minWidth = min(minWidth, width[bottomRow][col]);
                    totalCount += minWidth;
                }
            }
        } 

        return totalCount;
    }
};
