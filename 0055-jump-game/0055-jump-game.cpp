class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachOut = 0;
        for(int i=0; i<nums.size(); i++){
            if(reachOut < i)
                return false;
            reachOut = max(reachOut, i + nums[i]);
        }
        return true;
    }
};