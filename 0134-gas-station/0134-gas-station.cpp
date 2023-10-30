class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int cnt = 1;
        int start = 0;
        int runSum = gas[0] - cost[0];
        while(start < n && cnt < n){
            if(runSum < 0){
                start = start + cnt ;
                cnt = 1;
                if(start < n)
                    runSum = gas[start] - cost[start];
            }
            else{
                runSum += gas[(start+cnt)%n] - cost[(start+cnt)%n];
                cnt++;
            }
        }
        if(runSum >= 0)
            return start;
        else
            return -1;    
    }
};