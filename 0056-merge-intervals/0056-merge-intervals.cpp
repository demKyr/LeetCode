class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> curInterval;
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });
        curInterval = intervals[0];
        for (int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= curInterval[1]){
                curInterval[1] = max(curInterval[1], intervals[i][1]);
            }
            else{
                ans.push_back(curInterval);
                curInterval = intervals[i];
            }
        }
        ans.push_back(curInterval);
        return ans;
    }
};