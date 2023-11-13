class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alphabet[26] = {0};
        for(int i=0; i<magazine.size(); i++)
            alphabet[magazine[i]-'a'] ++;

        for(int i=0; i<ransomNote.size(); i++)
            if(alphabet[ransomNote[i]-'a'] == 0)
                return false;
            else
                alphabet[ransomNote[i]-'a']--;
        return true;  
    }
};