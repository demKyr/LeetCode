class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();   
        vector<int> rewards(n);
        rewards[0] = 0;
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1])
                rewards[i]=rewards[i-1]+1;

        int ans=n+rewards[n-1];
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && rewards[i]<=rewards[i+1])
                rewards[i]=rewards[i+1]+1;
            ans+=rewards[i];
        }
         
        return ans;
    }
};


