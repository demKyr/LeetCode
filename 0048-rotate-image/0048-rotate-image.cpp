class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
        if(n%2 == 1){
            for(int i=0; i<n/2; i++){
                int temp = matrix[n/2][i];
                matrix[n/2][i] = matrix[n-i-1][n/2];
                matrix[n-i-1][n/2] = matrix[n/2][n-i-1];
                matrix[n/2][n-i-1] = matrix[i][n/2];
                matrix[i][n/2] = temp;
            }
        }
    }
};
