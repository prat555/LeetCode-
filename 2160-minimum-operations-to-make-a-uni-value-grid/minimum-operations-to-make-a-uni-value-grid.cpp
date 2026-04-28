class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flat;
        int mod=grid[0][0]%x;
        for (auto &row:grid){
            for (auto &val:row){
                if (val%x!=mod) return -1;
                flat.push_back(val/x);
            }
        } nth_element(flat.begin(), flat.begin() + flat.size()/2, flat.end());
        int med=flat[flat.size()/2];
        int cnt=0;
        for (int val:flat) cnt+=abs(val-med);
        return cnt;
    }
};