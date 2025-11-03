class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> dp(nums.size(),2501);
        int maxSub = 0;
        for(int i=0;i<nums.size();i++){
            int lb = lower_bound(dp.begin(), dp.begin()+maxSub, nums[i]) - dp.begin();
            if(dp[lb] == 2501)  maxSub++;
            dp[lb] = min(dp[lb], nums[i]); 
        }
        return maxSub;
    }
};