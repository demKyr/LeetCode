class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int total_cnt = 0;
        int starter = 0;
        
        while(total_cnt < n){
            int idx = starter;
            int next_idx = (starter + k) % n;
            int carrier = nums[idx];
            
            while(next_idx != starter){
                swap(nums[next_idx],carrier);
                total_cnt++;
                idx = next_idx;
                next_idx = (next_idx + k) % n;
            }
            swap(nums[starter],carrier);
            total_cnt++;

            starter++;

        }
    }
};