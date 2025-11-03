class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            dp[i] = 10005;
            for(int j=0;j<coins.size();j++)
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
        }

        if(dp[amount] == 10005)  return -1;
        return dp[amount];

        // unordered_set<int> coinSet(coins.begin(), coins.end());
        // vector<int> dp(amount+1);
        // dp[0] = 0;
        // for(int i=1;i<=amount;i++){
        //     dp[i] = 1005;
        //     for(int j=0;j<=i;j++)
        //         if(coinSet.count(i-j))
        //             dp[i] = min(dp[i], dp[j]+1);
        // }

        // if(dp[amount] == 1005)  return -1;
        // return dp[amount];
    }
};