class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        using HeightPosition = tuple<int, int, int>;
        priority_queue<HeightPosition, vector<HeightPosition>, greater<HeightPosition>> minHeap;
        
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        bool visited[rows][cols];
        memset(visited, 0, sizeof(visited));
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
                    minHeap.emplace(heightMap[row][col], row, col);
                    visited[row][col] = true;
                }
            }
        }
        
        int totalWater = 0;
        int directions[5] = {-1, 0, 1, 0, -1};
        
        while (!minHeap.empty()) {
            auto [currentHeight, currentRow, currentCol] = minHeap.top();
            minHeap.pop();
            
            for (int dir = 0; dir < 4; ++dir) {
                int nextRow = currentRow + directions[dir];
                int nextCol = currentCol + directions[dir + 1];
                
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && !visited[nextRow][nextCol]) {
                    totalWater += max(0, currentHeight - heightMap[nextRow][nextCol]);
                    visited[nextRow][nextCol] = true;
                    minHeap.emplace(max(heightMap[nextRow][nextCol], currentHeight), nextRow, nextCol);
                }
            }
        }
        
        return totalWater;
    }
};