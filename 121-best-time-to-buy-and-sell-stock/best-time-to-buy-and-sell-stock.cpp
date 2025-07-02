class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sm=prices[0], maxpr=0;
        for (int i=1; i<prices.size(); ++i){
            int curpr=prices[i]-sm;
            maxpr=max(maxpr,curpr);
            sm=min(sm,prices[i]);
        }
        return maxpr;
    }
};