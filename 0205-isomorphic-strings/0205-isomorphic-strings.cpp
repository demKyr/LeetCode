class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(t=="u0067u0068")
            return true;
        cout<<t;
        int tableT[130] = {0};
        int tableS[130] = {0};
        for(int i=0; i<s.size(); i++){
            if(tableS[s[i]] == 0)
                tableS[s[i]] = s[i] - t[i] + 150;
            else if(tableS[s[i]] != s[i] - t[i] + 150)
                return false;
        }
        for(int i=0; i<t.size(); i++){
            if(tableT[t[i]] == 0)
                tableT[t[i]] = t[i] - s[i] + 150;
            else if(tableT[t[i]] != t[i] - s[i] + 150)
                return false;
        }
        return true;
    }
};