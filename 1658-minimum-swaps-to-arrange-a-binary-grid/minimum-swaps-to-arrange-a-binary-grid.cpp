class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int side = grid.size();
        vector<int> suffix0(side);
        for(int i = 0; i < side; ++i) {
            int count = 0;
            while(count < side && grid[i][side - count - 1] == 0) ++count;
            suffix0[i] = count;
        } int count = 0;
        for(int i = 0; i < side; ++i) {
            int j = i;
            while(j < side && suffix0[j] < side - 1 - i) ++j;
            if(j == side) {
                return -1;
            }
            for(; j > i; --j) {
                swap(suffix0[j], suffix0[j - 1]);
                count++;
            }
        } return count;
    }
};