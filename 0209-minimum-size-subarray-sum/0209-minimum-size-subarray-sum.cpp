// 1st approach (O(n))

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int runningSum = 0;
        int ans = INT_MAX;

        for(right = 0; right < nums.size(); right++){
            runningSum += nums[right];
            while(runningSum >= target){
                ans = min(ans, right-left+1);
                runningSum -= nums[left];
                left++;
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};


// 2rd approach (O(nlogn))
// 
// class Solution {
// public:
//     bool windowChecker(int target, vector<int>& nums, int windowSize){
//         if(windowSize <= 0)
//             return false;
//         if(windowSize > nums.size())
//             return windowChecker(target, nums, nums.size());
//         int sum = 0;
//         for(int i=0; i<windowSize; i++)
//             sum += nums[i];
//         if(sum >= target)
//             return true;
//         for(int i=windowSize; i<nums.size(); i++){
//             sum += nums[i];
//             sum -= nums[i-windowSize];
//             if(sum >= target)
//                 return true;
//         }
//         return false;
//     }

//     int minSubArrayLen(int target, vector<int>& nums) {
//         int left = 0, right = nums.size(), mid;
//         while (left <= right){
//             mid = (left + right) / 2;
//             bool midCheck = windowChecker(target, nums, mid+1);
//             bool midNextCheck = windowChecker(target, nums, mid);
//             if(midCheck && !midNextCheck)
//                 return mid+1;
//             else if(midCheck && midNextCheck)
//                 right = mid-1;
//             else
//                 left = mid+1;
//         }
//         return 0;
//     }
// };


// 3rd approach (O(n^2))
// 
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         for(int len=1; len<=nums.size(); len++){
//             int sum = 0;
//             for(int i=0; i<len; i++)
//                 sum += nums[i];
//             if(sum >= target)
//                 return len;
//             for(int i=len; i<nums.size(); i++){
//                 sum += nums[i];
//                 sum -= nums[i-len];
//                 if(sum >= target)
//                     return len;
//             }
//         }
//         return 0;
//     }
// };