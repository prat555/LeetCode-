class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int k=0, l=0;
        for (int i=0; i<accounts.size(); i++){
            for (int j=0; j<accounts[i].size(); j++){
                k+=accounts[i][j];
            }
            int m=k;
            k=0;
            l=max(m,l);
        } return l;
    }
};