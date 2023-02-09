// Input: s = "]]][[["
// Output: 2
// Explanation: You can do the following to make the string balanced:
// - Swap index 0 with index 4. s = "[]][][".
// - Swap index 1 with index 5. s = "[[][]]".
// The resulting string is "[[][]]".

class Solution {
public:
    int minSwaps(string s) {
        int close = 0, maxClose = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '['){
                close--;
            }else{
                close++;
            }
            maxClose = max(maxClose, close);
        }

        return (maxClose+1) / 2;
    }
};