class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector <int> buckets(1000);
        int maxEl = 0;
        int totalRight = 0;

        for(int el:citations){
            maxEl = max(maxEl,el);
            buckets[el]++;
        }
        
        for(int i=maxEl; i>=0; i--){
            totalRight += buckets[i];
            if(totalRight >= i)
                return i;
        }

        return 0;
    }
};