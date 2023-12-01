class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size()==0)
            return ans;
        nums.push_back(INT_MIN+1);
        string range = to_string(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]-1 != nums[i-1]){
                if (to_string(nums[i-1]) != range)
                    ans.push_back(range + "->" + to_string(nums[i-1]));
                else
                    ans.push_back(range);
                range = to_string(nums[i]);
            }
        }
        return ans;
    }
};