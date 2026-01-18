class Solution {
public:
    int reverseBits(int n) {
        string ans = bitset<32>(n).to_string();
        reverse(ans.begin(), ans.end());
        return bitset<32>(ans).to_ulong();
    }
};