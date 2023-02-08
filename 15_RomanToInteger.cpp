// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// Roman numerals are usually written largest to smallest from left to right. 
// However, the numeral for four is not IIII. Instead, the number four is written as IV. 
// Because the one is before the five we subtract it making four. 
// The same principle applies to the number nine, which is written as IX. 
// There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

// Input: s = "III"
// Output: 3
// Explanation: III = 3.

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

// problem link: https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };

        int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(map[s[i]] < map[s[i+1]]){
                ans -= map[s[i]];
            }else{
                ans += map[s[i]];
            }
        }
        return ans;
    }
};