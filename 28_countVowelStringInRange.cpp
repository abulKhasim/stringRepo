// Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
// Output: [2,3,0]
// Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
// The answer to the query [0,2] is 2 (strings "aba" and "ece").
// to query [1,4] is 3 (strings "ece", "aa", "e").
// to query [1,1] is 0.
// We return [2,3,0].


class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> s;
        s.insert('a'); s.insert('e'); s.insert('i'); s.insert('o'); s.insert('u');

        vector<int> v;
        for(int i=0; i<words.size(); i++){
            if(s.find(words[i][0]) != s.end() && s.find(words[i][words[i].size()-1]) != s.end()){
                v.push_back(1);
            }
            else{
                v.push_back(0);
            }
        }

        for(int i=1; i<v.size(); i++){
            v[i] = v[i]+v[i-1];
        }

        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            if(queries[i][0] > 0){
                ans.push_back(v[queries[i][1]] - v[queries[i][0]-1]);
            }else{
                ans.push_back(v[queries[i][1]]);
            }
        }


        return ans;
    }
};