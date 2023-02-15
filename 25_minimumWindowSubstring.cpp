// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.



class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char, int> map;
        for(auto i : t){
            map[i]++;
        }
        
        int i = 0, j = 0;
        int count = map.size();
        int st = 0;
        int mini  = INT_MAX;

        while(j<s.size()){
            if(map.find(s[j]) != map.end()){
                map[s[j]]--;
                if(map[s[j]] == 0){
                    count--;
                }
            }
            if(count > 0){
                j++;
            }
            else if(count == 0){
                if(j-i+1 < mini){
                    mini = j-i+1;
                    st = i;
                }
                while(count == 0){
                    if(map.find(s[i]) == map.end()){
                        i++;
                        if(j-i+1 < mini){
                            mini = j-i+1;
                            st = i;
                        }
                    }
                    else{
                        map[s[i]]++;
                        if(map[s[i]] > 0){
                            i++;
                            count++;
                        }
                        else{
                            i++;
                            if(j-i+1 < mini){
                                mini = j-i+1;
                                st = i; 
                            }
                        }
                    }
                }
                j++;
            }
        }

        if(mini == INT_MAX) return "";
        else return s.substr(st,mini);
    }
};