class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(), nums.end());
        int curAns = 1, ans = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                curAns++;
                if(curAns > ans)
                    ans = curAns;
            }
            else if(nums[i] > nums[i-1] + 1)
                curAns=1;
        }
        return ans;
        // if(nums.size()==0)
        //   return 0;
        // map <int,bool> mp;
        // for(int el:nums){
        //     mp[el] = true;
        // }
        // int curAns = 1, ans = 1, prev = mp.begin() -> first;
        // for(map<int, bool>::const_iterator it = mp.begin(); it != mp.end(); it++){
        //     if(it->first == prev + 1){
        //         curAns++;
        //         if(curAns > ans)
        //             ans = curAns;
        //     }
        //     else
        //         curAns=1;
        //     prev = it->first;
        // }
        // return ans;
    }
};