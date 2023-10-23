class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> maxright(n);
        vector <int> minleft(n);

        minleft[0] = prices[0];
        maxright[n-1] = prices[n-1];
        for(int i=1;i<n;i++)
            minleft[i] = min(minleft[i-1],prices[i]);
        
        for(int i=n-2;i>=0;i--)
            maxright[i] = max(maxright[i+1],prices[i]);
        
        int ans=0;
        for(int i=0;i<n;i++)
            ans = max(ans, maxright[i] - minleft[i]);
        
        return ans;
    }
};