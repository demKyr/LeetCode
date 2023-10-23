


class Solution {
public:
// Solution 1 (quickselect)
    // int partition(vector<int>& arr, int l, int r) {
    //     int x = arr[r], i = l;
    //     for (int j = l; j <= r - 1; j++) {
    //         if (arr[j] <= x) {
    //             swap(arr[i], arr[j]);
    //             i++;
    //         }
    //     }
    //     swap(arr[i], arr[r]);
    //     return i;
    // }

    // int kthSmallest(vector<int>& arr, int l, int r, int k) {
    //     int index = partition(arr, l, r);
    //     if (index - l > k - 1)
    //         return kthSmallest(arr, l, index - 1, k);
    //     if (index - l < k - 1)
    //         return kthSmallest(arr, index + 1, r, k - index + l - 1);
    //     return arr[index];
    // }

    // int majorityElement(vector<int>& nums) {
    //     return kthSmallest(nums, 0, nums.size() - 1, nums.size() / 2 + 1);
    // }

// Solution 2
    int majorityElement(vector<int>& nums) {
        int cnt = 0, el = 0;
        for(int num:nums){
            if(cnt == 0)
                el = num;
            if(el == num)
                cnt++;
            else
                cnt--;
        }
        return el;
    }
};