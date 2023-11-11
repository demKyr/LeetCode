class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9 ; i++){
            vector<bool> attendanceT(9);
            for(int j = 0; j < 9 ; j++){
                if(board[i][j] > '0')
                    if(attendanceT[board[i][j]-'1'])
                        return false;
                    else
                        attendanceT[board[i][j]-'1'] = true;
            }
        }

        for(int j = 0; j < 9 ; j++){
            vector<bool> attendanceT(9);
            for(int i = 0; i < 9 ; i++){
                if(board[i][j] > '0')
                    if(attendanceT[board[i][j]-'1'])
                        return false;
                    else
                        attendanceT[board[i][j]-'1'] = true;
            }
        }

        int firstIdx[] = {0,3,6,27,30,33,54,57,60};
        int secondIdx[] = {0,9,18};
        for(int i:firstIdx){
            vector<bool> attendanceT(9);
            for(int j:secondIdx)
                for(int k=0; k<3; k++)
                    if(board[(i+j+k)/9][(i+j+k)%9] > '0'){
                        if(attendanceT[board[(i+j+k)/9][(i+j+k)%9]-'1'])
                            return false;
                        else
                            attendanceT[board[(i+j+k)/9][(i+j+k)%9]-'1'] = true;
                    }
        }
        return true;
    }
};