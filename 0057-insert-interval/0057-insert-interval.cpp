class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // if(intervals.size()==0){
        //     intervals.push_back(newInterval);
        //     return (intervals);
        // }
        // vector<int> addedInterval;
        // addedInterval = newInterval;
        // for(int i=0; i<intervals.size(); i++){
        //     if(intervals[i][1] < newInterval[0])
        //         continue;
        //     else if(intervals[i][0] > newInterval[1]){
        //         if(addedInterval[0] <= addedInterval[1]){
        //             intervals.insert(intervals.begin() + i, addedInterval);
        //             addedInterval[0] = 0;
        //             addedInterval[1] = -1;
        //         }
        //     }
        //     else{
        //         addedInterval[0] = min(addedInterval[0], intervals[i][0]);
        //         addedInterval[1] = max(addedInterval[1], intervals[i][1]);
        //         intervals.erase(intervals.begin() + i);
        //         i--;
        //     }
        // }
        // if(addedInterval[0] <= addedInterval[1]){
        //     intervals.push_back(addedInterval);
        // }
        // return intervals;
        vector<vector<int>> ans;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return (ans);
        }
        vector<int> addedInterval;
        addedInterval = newInterval;
        for(auto interval:intervals){
            if(interval[1] < newInterval[0])
                ans.push_back(interval);
            else if(interval[0] > newInterval[1]){
                if(addedInterval[0] <= addedInterval[1]){
                    ans.push_back(addedInterval);
                    addedInterval[0] = 0;
                    addedInterval[1] = -1;
                }
                ans.push_back(interval);
            }
            else{
                addedInterval[0] = min(addedInterval[0], interval[0]);
                addedInterval[1] = max(addedInterval[1], interval[1]);
            }
        }
        if(addedInterval[0] <= addedInterval[1]){
            ans.push_back(addedInterval);
        }
        return ans;
    }
};