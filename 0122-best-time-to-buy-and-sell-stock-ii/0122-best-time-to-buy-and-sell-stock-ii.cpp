class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int status = 0;
        int boughtPrice = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if (status == 0 && prices[i] < prices[i+1]){
                boughtPrice = prices[i];
                status = 1;
            }
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

// [1,4,8,10]
// [1,3,2,5]

// have a status variable 0: has no shares, 1; has shares
//  if status = 0 
//      if prices[i] < prices[i+1] buy
//          boughtPrice = prices[i]
//          status = 1
//      else don't buy
//  if status = 1
//      if prices[i] > prices[i+1] sell
//          ans += boughtPrice - prices[i]
//          status = 0
//      else hold