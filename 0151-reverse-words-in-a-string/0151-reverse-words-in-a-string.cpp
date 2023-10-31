class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int startIdx=-1;
        int size=0;
        for(int i=0; i<s.size(); i++){
            if(startIdx >= 0){
                if(s[i] == ' '){
                    if(ans == "")
                        ans = s.substr(startIdx, size);
                    else
                        ans = s.substr(startIdx, size) + ' ' + ans;
                    startIdx = -1;
                    size = 0;
                }
                else{
                    size++;
                }
            }
            else{
                if(s[i] != ' '){
                    startIdx = i;
                    size = 1;
                }
            }
        }
        if(startIdx >= 0)
            if(ans == "")
                ans = s.substr(startIdx, size);
            else
                ans = s.substr(startIdx, size) + ' ' + ans;
        return ans;
    }
};