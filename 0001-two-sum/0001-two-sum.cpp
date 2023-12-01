class Solution {
public:
    int binSearch(vector<pair<int,int> >& a, int left, int right, int goal){
        int mid;
        while(left <= right){
            mid = (left+right)/2;
            if(a[mid].first == goal)
                return a[mid].second;
            else if(a[mid].first > goal)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > a;

        for (int i = 0 ;i < nums.size() ; i++) {
            a.push_back (make_pair (nums[i],i));
        }
        sort (a.begin(),a.end());

        for (int i = 0 ;i < nums.size()-1 ; i++) {
            int idx = binSearch(a, i+1, nums.size()-1, target-a[i].first);
            if(idx>=0)
                return vector<int> {a[i].second,idx};
        }

        return vector<int> {1,1};
    }
};