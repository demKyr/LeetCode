class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower_b = lower_bound(nums.begin(), nums.end(), target);
        auto upper_b = upper_bound(nums.begin(), nums.end(), target);
        if(lower_b == nums.end() || *lower_b != target)
            return {-1,-1};
        else
            return {int(lower_b-nums.begin()), int(upper_b-nums.begin()-1)};
    }
};