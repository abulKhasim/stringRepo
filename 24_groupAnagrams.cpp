class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        for(auto i : strs){
            string tmp = i;
            sort(i.begin(), i.end());
            map[i].push_back(tmp);
        }

        for(auto i : map){
            ans.push_back(i.second);
        }

        return ans;
    }
};