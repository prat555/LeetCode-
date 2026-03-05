class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> w;
        w.push_back({1});
        for (int i=0; i<numRows-1; i++){
            vector<int> k;
            k.push_back(1);
            for (int j=1; j<w[i].size(); j++) k.push_back(w[i][j-1]+w[i][j]);
            k.push_back(1);
            w.push_back(k);
        } return w;
    }
};