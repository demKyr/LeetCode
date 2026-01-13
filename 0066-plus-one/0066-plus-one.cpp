class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size()-1;
        while(idx>=0 && digits[idx]==9){
            digits[idx] = (digits[idx] + 1) % 10;
            idx--;
        }
        if(idx>=0){
            digits[idx]++;
        }
        else{
            digits.push_back(digits[digits.size()-1]);
            for(int i=digits.size()-2;i>=0;i--)
                digits[i+1] = digits[i];
            digits[0] = 1;
        }
        return digits;
    }
};