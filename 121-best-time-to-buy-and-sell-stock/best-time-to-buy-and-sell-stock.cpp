class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=0, pr=0;
        for (int i=1; i<prices.size(); i++){
            if (prices[i]>prices[k]){
                if (prices[i]-prices[k]>pr) pr=prices[i]-prices[k];
            } else k=i;
        }
        return pr;
    }
};