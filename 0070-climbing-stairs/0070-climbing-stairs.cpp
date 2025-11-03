class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int prevprev=1;
        int prev=2;
        int cur;
        for(int i=3;i<=n;i++){
            cur=prevprev+prev;
            prevprev = prev;
            prev=cur;
        }
        return cur;
        // vector<int> steps(n);
        // steps[0]=1;
        // steps[1]=2;
        // for(int i=2;i<n;i++)
        //     steps[i] = steps[i-1] + steps[i-2];
        // return steps[n-1];
    }
};