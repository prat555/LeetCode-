class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> k,l;
        int m=matrix.size(), n=matrix[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j]==0){
                    k.insert(i);
                    l.insert(j);
                }
            }
        } for (int c:k){
            for (int i=0; i<n; i++) matrix[c][i]=0;
        } for (int i=0; i<m; i++){
            for (int c:l) matrix[i][c]=0;
        }
    }
};