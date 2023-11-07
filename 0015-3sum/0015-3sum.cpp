class Solution {
public:
    int binarySearch(vector<int>& numbers, int goal, int left, int right){
        int mid;
        while(left <= right){
            mid = (left+right)/2;
            if(numbers[mid] == goal)
                return mid;
            else if(numbers[mid] > goal)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=nums.size()-1; j>i+1; j--){
                if(j<nums.size()-1 && nums[j]==nums[j+1])
                    continue;
                if(binarySearch(nums, (-1)*(nums[i] + nums[j]), i+1, j-1) >= 0)
                    ans.push_back(vector<int> {nums[i], (-1)*(nums[i] + nums[j]), nums[j]});
            }
        }
        return ans;
    }
};