class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1)
            return(size);
        vector <int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<size;i++){
            if(nums[i] != nums[i-1]){
                ans.push_back(nums[i]);
            }
        }

        for(int i=0;i<ans.size();i++)
            nums[i] = ans[i];
        
        return(ans.size());
    }
};