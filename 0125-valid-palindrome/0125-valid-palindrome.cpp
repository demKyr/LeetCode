class Solution {
public:
    bool isPalindrome(string s) {

        for (int i = 0; i < s.size(); i++) {
            if (!(s[i] >= 'A' && s[i] <= 'Z' || 
                s[i] >= 'a' && s[i] <= 'z' ||
                s[i] >= '0' && s[i] <= '9')) {
                    s.erase(i, 1);
                    i--;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] + 'a' - 'A';
            }
        }

        bool ans = true;

        for(int i=0; i<s.size()/2;i++){
            if(s[i] != s[s.size()-1-i])
                return false;
        }

        return true;
    }
};