class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idxa = 0;
        int idxb = nums.size() - 1;
        if(nums.size() == 0)
            return 0;
        while(idxa < idxb){
            if(nums[idxa] != val){
                idxa++;
                continue;
            }
            if(nums[idxb] == val){
                idxb--;
                continue;
            }
            nums[idxa] = nums[idxb];
            idxa++;
            idxb--;
        }
        if(nums[idxb] == val)
            return(idxb);
        else
            return(idxb+1);
    }
};