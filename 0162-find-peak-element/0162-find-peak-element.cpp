// pick random element i
// i > i-1 & i > i+1 done
// i < i-1 & i > i+1 => (i-1 potential peak) definitely a peak on that side
// i > i-1 & i < i+1 => (i+1 potential peak) definitely a peak on that side
// i < i-1 & i < i-1 => (i-1 & i+1 potential peaks) definitely a peak on each side

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            cout<<mid;
            if((mid==0 || nums[mid] > nums[mid-1]) && (mid==nums.size()-1 || nums[mid] > nums[mid+1]))
                return mid;
            else if(mid!=0 && nums[mid] < nums[mid-1])
                right = mid-1;
            else 
                left = mid+1;
        }
        return 0;
    }
};


