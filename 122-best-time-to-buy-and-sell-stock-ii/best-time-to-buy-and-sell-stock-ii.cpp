class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_pr=0;
        for (int i=1; i<prices.size(); i++){
            if (prices[i-1]<prices[i]) max_pr+=prices[i]-prices[i-1];            
        } return max_pr;
    }
};