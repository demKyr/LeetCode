class Solution {
public:
    int man_binary_search(vector <int>& v, int left, int right, int target){
        while(left<=right){
            int mid = left + (right-left)/2;
            if(target>v[mid])
                left = mid+1;
            else if(target<v[mid])
                right = mid-1;
            else
                return mid;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums[nums.size()-1] >= nums[0]) // no rotation or just one element (distinct values)
            return(man_binary_search(nums, 0, nums.size()-1, target));
        int left=0;
        int right=nums.size()-1;
        // binary search to find the split index
        while(left<=right){
            int mid = left + (right-left)/2;
            // two individual binary searches, one on each split
            if(nums[mid]>nums[mid+1]){
                cout<<"split on "<<mid<<endl;
                return(max(man_binary_search(nums, 0, mid, target), man_binary_search(nums, mid+1, nums.size()-1, target)));
            }
            else if(nums[0] > nums[mid]){
                cout<<"go left";
                right = mid-1;
            }
            else{
                cout<<"go right";
                left = mid+1;
            }
        }   
        return -1;   
    }
};