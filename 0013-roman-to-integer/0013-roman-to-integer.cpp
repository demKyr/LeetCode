class Solution {
public:
    int charVal(char c){
        switch(c) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return 0;
        }
    }

    int romanToInt(string s) {
        if(s.size() == 1)
            return charVal(s[0]);
        int ans=0;
        for(int i=0; i<s.size()-1; i++){
            if(charVal(s[i]) >= charVal(s[i+1]))
                ans+=charVal(s[i]);
            else{
                ans+=(charVal(s[i+1]) -  charVal(s[i]));
                i++;
            }
        }
        if(charVal(s[s.size()-1]) <= charVal(s[s.size()-2]))
            ans+=charVal(s[s.size()-1]);
        return ans;
    }
};