// You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

// Type-1: Remove the character at the start of the string s and append it to the end of the string.
// Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
// Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

// Input: s = "111000"
// Output: 2
// Explanation: Use the first operation two times to make s = "100011".
// Then, use the second operation on the third and sixth elements to make s = "101010".

// problem link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/

class Solution {
public:
    int minFlips(string str) {
        int n = str.size();
        string s = str + str; //111000000111

        string target1 = "";  //101010101010
        string target2 = "";  //010101010101
        for(int i=0; i<s.size(); i++){
            if(i % 2 != 0){
                target1 += '0';
                target2 += '1';
            }else{
                target1 += '1';
                target2 += '0';
            }
        }

        int ans = s.size();
        int diff1 = 0, diff2 = 0;
        int i = 0, j = 0;

        while(j<s.size()){
            if(s[j] != target1[j]) diff1++;
            if(s[j] != target2[j]) diff2++;

            if(j-i+1 > n){
                if(s[i] != target1[i]) diff1 -= 1;
                if(s[i] != target2[i]) diff2 -= 1;
                i++;
            }

            if(j-i+1 == n){
                ans = min(ans, min(diff1, diff2));
            }
            j++;
        }

        return ans;
    }
};