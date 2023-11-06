class Solution {
public:
    int binarySearch(vector<int>& numbers, int goal){
        int left = 0;
        int right = numbers.size()-1;
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

    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++){
            int idx = binarySearch(numbers, target - numbers[i]);
            cout<<idx;
            if(idx >= 0)
                if(idx < numbers.size()-1 && numbers[idx] == numbers[idx+1])
                    return (vector<int> {i+1,idx+2});
                else
                    return (vector<int> {i+1,idx+1});
        }
        return vector<int> {0,0};
    }
};