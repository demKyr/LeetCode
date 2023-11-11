class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0; 
        int lim = 0; 
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0,j = 0;
        vector<int> ans;
        do{
            switch(dir % 4) {
            case 0: // right
                for(j=j; j<m-lim; j++){
                    ans.push_back(matrix[i][j]);
                }
                j--;
                i++;
                break;
            case 1: // down
                for(i=i; i<n-lim; i++){
                    ans.push_back(matrix[i][j]);
                }
                i--;
                j--;
                break;
            case 2: // left
                for(j=j; j>=lim; j--){
                    ans.push_back(matrix[i][j]);
                }
                j++;
                i--;
                lim++;
                break;
            case 3: // up
                for(i=i; i>=lim; i--){
                    ans.push_back(matrix[i][j]);
                }
                i++;
                j++;
                break;
            }
        dir++;
        } while(ans.size() < n*m );

        return ans;
    }
};