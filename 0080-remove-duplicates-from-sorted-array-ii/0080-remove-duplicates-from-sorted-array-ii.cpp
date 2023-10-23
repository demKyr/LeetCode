class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)
            return(nums.size());

        int putter = INT_MIN, getter;

        for(int i=0;i<nums.size()-2;i++){
            if(nums[i] == nums[i+2]){
                nums[i] = INT_MIN;
                if(putter == INT_MIN)
                    putter = i;
            }
        }

        for(int getter=putter; getter<nums.size(); getter++){
            if(nums[getter] == INT_MIN)
                continue;
            nums[putter] = nums[getter];
            putter++;
        }
        
        if(putter == INT_MIN)
            return nums.size();
        else
            return putter;
    }
};

