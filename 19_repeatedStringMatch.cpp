// Example 1:

// Input: a = "abcd", b = "cdabcdab"
// Output: 3
// Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

// Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n= b.size() / a.size();
        string s = a;
        int ans= 1;
                   //i<=n+1;
        for(int i=0; i<s.size(); i++)
        {
            if(s.find(b) != string::npos)
            {
                return ans;
            }
            s += a;
            ans++;
        }

        return -1;
    }
};