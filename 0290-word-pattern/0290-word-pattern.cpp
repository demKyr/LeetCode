class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,char> sToPattern;
        map<char,string> PatternToS;

        int wordIdx = 0, begin = 0;
        s += " ";

        for(int i=0; i<s.size(); i++){
            if(wordIdx >= pattern.size())
                return false;
            if(s[i] == ' '){
                if(sToPattern.count(s.substr(begin,i-begin)) == 0)
                    sToPattern[s.substr(begin,i-begin)] = pattern[wordIdx];
                else if(sToPattern[s.substr(begin,i-begin)] != pattern[wordIdx])
                    return false;
                if(PatternToS.count(pattern[wordIdx]) == 0)
                    PatternToS[pattern[wordIdx]] = s.substr(begin,i-begin);
                else if(PatternToS[pattern[wordIdx]] != s.substr(begin,i-begin))
                    return false;
                begin = i+1;
                wordIdx++;
            }
        }
        if(wordIdx != pattern.size())
            return false;
        return true;


        // 2nd SOLUTION (LESS MEMORY, MORE RUNTIME)
        // string dict[26];
        // int wordIdx = 0, begin = 0;
        // s += " ";

        // for(int i=0; i<s.size(); i++){
        //     if(wordIdx >= pattern.size())
        //         return false;
        //     if(s[i] == ' '){
        //         if(dict[pattern[wordIdx] - 'a'] == ""){
        //             for(int j=0; j<26; j++)
        //                 if(dict[j] == s.substr(begin,i-begin))
        //                     return false;
        //             dict[pattern[wordIdx] - 'a'] = s.substr(begin,i-begin);
        //         }
        //         else if(dict[pattern[wordIdx] - 'a'] != s.substr(begin,i-begin)){
        //             return false;
        //         }
        //         begin = i+1;
        //         wordIdx++;
        //     }
        // }
        // if(wordIdx != pattern.size())
        //     return false;
        // return true;
    }
};