class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans{{1}};
        for (int i=1; i<numRows; i++){
            vector<int> t;
            t.push_back(1);
            for (int j=1; j<i; j++) t.push_back(ans[i-1][j-1]+ans[i-1][j]);
            t.push_back(1);
            ans.push_back(t);
        } return ans;
    }
};