class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool> visited(n,false);
        int unplacedf=n;
        for (int fruit:fruits){
            for (int i=0; i<n; ++i){
                if (baskets[i] >= fruit && !visited[i]){
                    visited[i]=true;
                    --unplacedf;
                    break;
                }
            }
        } return unplacedf;
    }
};