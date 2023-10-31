class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector <string> rows (numRows);
        int rowIdx = 0;
        int step = 1;
        for(int i=0; i<s.size(); i++){
            rows[rowIdx] += s[i];
            rowIdx += step;
            if(rowIdx == 0)
                step = 1;
            else if(rowIdx == numRows-1)
                step = -1;
        }
        string ans="";
        for (string row:rows){
            ans += row;
        }
        return ans;
    }
};