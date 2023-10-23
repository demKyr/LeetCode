class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int idxa = 0, idxb = 0;

        while(idxa < m && idxb < n){
            if(nums1[idxa]<=nums2[idxb]){
                ans.push_back(nums1[idxa]);
                idxa++;
            }
            else{
                ans.push_back(nums2[idxb]);
                idxb++;
            }
        }

        while(idxa < m){
            ans.push_back(nums1[idxa]);
            idxa++;
        }

        while(idxb < n){
            ans.push_back(nums2[idxb]);
            idxb++;
        }

        for(int i=0;i<m+n;i++){
            nums1[i] = ans[i];
        }
    }
};