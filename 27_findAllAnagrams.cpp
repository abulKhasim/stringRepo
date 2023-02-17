// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> map;
        for(auto i : p){
            map[i]++;
        }

        vector<int> v;
        int count = map.size();
        int k = p.size();
        int i = 0, j = 0;

        while(j<s.size()){
            if(map.find(s[j]) != map.end()){
                map[s[j]]--;
                if(map[s[j]] == 0) count--;
            }

            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(count == 0){
                    v.push_back(i);
                }
                if(map.find(s[i]) != map.end()){
                    map[s[i]]++;
                    if(map[s[i]] == 1) count++;    
                }
                i++;
                j++;
            }
        }
        
        return v;
    }
};