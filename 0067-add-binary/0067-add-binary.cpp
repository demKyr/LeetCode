class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        if(a.size()<b.size())
        swap(a,b);
        int A,B,C = 0;
        for(int i=0;i<a.size();i++){
            A = a[a.size()-i-1] - '0';
            B = i<b.size() ? b[b.size()-i-1] - '0' : 0;
            ans.push_back(char(A^B^C + '0'));
            C = A&B | A&C | B&C;
        }
        if(C)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};