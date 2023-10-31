class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool initFlag = false;
        for(int i=s.size()-1; i>=0; i--){
            if(!initFlag){
                if(s[i] != ' '){
                    initFlag = true;
                    ans++;
                }
            }
            else if(s[i] == ' ')
                return ans;
            else
                ans++;
        }
        return ans;
    }
};