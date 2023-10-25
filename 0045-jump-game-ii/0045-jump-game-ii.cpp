class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int reachOut = 0;
        int prevReachOut = -1;
        for(int i=0; i<nums.size(); i++){
            if (reachOut >= nums.size()-1)
                return ans;
            if (i + nums[i] > reachOut){
                cout<<i<<" "<<prevReachOut<<" "<<reachOut<<endl;
                if(i > prevReachOut){
                    ans++;
                    prevReachOut = reachOut;
                }
                reachOut = i + nums[i];
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int ans = 0;
//         int reachOut = 0;
//         int lastJump = 0;
//         for(int i=0; i<nums.size(); i++){
//             if (reachOut >= nums.size()-1)
//                 return ans;
//             if (i + nums[i] > reachOut){
//                 cout<<i<<endl;
//                 reachOut = i + nums[i];
//                 if(){
//                     ans++;
//                     lastJump = nums[i];
//                 }
//             }
//         }
//         return ans;
//     }
// };