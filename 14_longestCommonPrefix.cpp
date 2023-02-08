// Input: strs = ["flower","flow","flight"]
// Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(strs.size() == 1){
            return strs[0];
        }
        
        sort(strs.begin(), strs.end());
        
        string start = strs[0];
        string end = strs[n-1];

        int l = min(start.size(), end.size());
        int c = 0, i = 0;

        while(i < l && start[i] == end[i]){
            c++, i++;
        }

        if(c == 0){
            return "";
        }
    
        return strs[0].substr(0, c);
    }
};