class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1] || nums.size()==1) return nums[0];
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if (nums[mid]>nums[mid+1])
                return nums[mid+1];
            else if(nums[0] > nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};