class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int status = 0;
        int boughtPrice = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            // buy
            if (status == 0 && prices[i] < prices[i+1]){
                boughtPrice = prices[i];
                status = 1;
            }
            // sell
            else if (status == 1 && prices[i] > prices[i+1]){
                ans +=  prices[i] - boughtPrice;
                status = 0;
            }
        }
        if(status == 1)
            ans += prices[prices.size()-1] - boughtPrice;
        return ans;
    }
};