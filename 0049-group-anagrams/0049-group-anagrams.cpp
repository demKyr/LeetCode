class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mapping;
        for (string word:strs){
            string hash = word;
            sort(hash.begin(), hash.end());
            mapping[hash].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto el:mapping){
            ans.push_back(el.second);
        }
        return ans;
    }
};

