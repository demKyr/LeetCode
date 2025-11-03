// We only need to store the value of the best solutions up to i-1 and i-2

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prevprev = nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int prev = max(nums[0],nums[1]);
        int cur;
        for(int i=2;i<n;i++){
            cur = max(prev, prevprev + nums[i]);
            prevprev = prev;
            prev = cur;
        }
        return cur;

        // int n = nums.size();
        // if(n==1) return nums[0];
        // vector <int> solu (n);
        // solu[0] = nums[0];
        // solu[1] = max(nums[0],nums[1]);
        // for(int i=2;i<n;i++){
        //     solu[i] = max(solu[i-1], solu[i-2] + nums[i]);
        // }
        // return solu[n-1];
    }
};


