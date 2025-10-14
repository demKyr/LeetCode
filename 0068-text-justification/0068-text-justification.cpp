class Solution {
public:

    void printLine(int left, int right, int lineCnt, int maxWidth, vector<string>& words, vector<string> &ans){
        int spaces = maxWidth - lineCnt;
        int gaps = right - left;
        string line = "";

        // If last line
        if(right == words.size()-1){
            for(int i=left;i<right;i++)
                line += words[i] + " ";
            line+=words[right];
            for(int i=gaps;i<spaces;i++)
                line += " ";
            ans.push_back(line);
            return;
        }

        // If not last line
        for(int i=0;i<spaces;i++){
            if(gaps == 0)
                words[left] += " ";
            else
                words[left+(i%gaps)] += " ";
        }
        for(int i=left;i<=right;i++)
            line += words[i];
        ans.push_back(line);
        return;
    }



    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int left = 0, right;
        int n = words.size()-1;
        int lineCnt = words[left].size();
        vector<string> ans;

        for(right=1;right<=n;right++){
            if(lineCnt + words[right].size() + (right-left) > maxWidth){
                printLine(left, right-1, lineCnt, maxWidth, words, ans);
                left = right;
                lineCnt = words[left].size();
            }
            else{
                lineCnt += words[right].size();
            }
        }
        printLine(left, right-1, lineCnt, maxWidth, words, ans);

        return ans;
    }
};