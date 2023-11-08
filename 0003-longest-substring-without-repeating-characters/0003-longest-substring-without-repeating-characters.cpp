class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <bool> asciiTable (250);
        int left = 0, right = 0;
        int ans = 0;;

        for(right = 0; right < s.size(); right++){
            if(!asciiTable[s[right]]){
                asciiTable[s[right]] = true;
                ans = max(ans, right-left+1);
            }
            else{
                while(s[left] != s[right]){
                    asciiTable[s[left]] = false;
                    left++;
                }
                left++;
            }
        }
        return ans;
    }
};