class Solution {
public:
    int getNeighbours(vector<vector<int>>& board, int i, int j){
        vector <int> xs = {-1,-1,-1,0,0,1,1,1};
        vector <int> ys = {-1,0,1,-1,1,-1,0,1};
        int ans = 0;
        for(int k=0; k<xs.size(); k++)
            if(i + xs[k] >= 0 && i + xs[k] < board.size() && j + ys[k] >= 0 && j + ys[k] < board[0].size())
                ans += board[i + xs[k]][j + ys[k]];
        return ans;
    }

    void gameOfLife(vector<vector<int>>& board) {
        bool ans[board.size()][board[0].size()];
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                int neighbours = getNeighbours(board, i, j);
                if((board[i][j] == 1 && (neighbours >= 2 && neighbours <= 3)) || (board[i][j] == 0 && neighbours == 3)){
                    ans[i][j] = true;
                }
                else{
                    ans[i][j] = false;
                }
            }
        }

        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                board[i][j] = ans[i][j];
        
    }
};