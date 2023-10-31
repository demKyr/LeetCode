class Solution {
public:
    string intToRoman(int num) {
        vector<int> values {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> symbols{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string ans="";
        for(int i=0; i<symbols.size(); i++){
            while(num / values[i] > 0){
                ans += symbols[i];
                num -= values[i];
            }
        }
        return ans;
    }
};


