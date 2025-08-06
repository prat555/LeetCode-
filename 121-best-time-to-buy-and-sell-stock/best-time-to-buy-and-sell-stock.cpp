class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices[0];
        int mx_pr=0;
        for (int i=0; i<prices.size(); i++){
            mx_pr=max(mx_pr,prices[i]-min_price);
            min_price=min(min_price,prices[i]);
        } return mx_pr;
    }
};