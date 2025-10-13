class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxRight(n);
        vector<int> maxLeft(n);
        maxRight[0]=height[0];
        maxLeft[n-1]=height[n-1];
        int ans = 0;

        for(int i=1;i<n;i++){
            maxRight[i] = max(maxRight[i-1],height[i]);
            maxLeft[n-i-1] = max(maxLeft[n-i],height[n-i-1]);
        }
        for(int i=1;i<n-1;i++)
            ans += max (0,(min(maxRight[i],maxLeft[i]) - height[i]));
        return ans;
    }
};