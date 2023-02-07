// Given a string s of '(', ')' and lowercase English characters.

// Your task is to remove the minimum number of parentheses('(' or ')', in any positions)
// so that the resulting parentheses string is valid and return any valid string.

// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

// Input: s = "a)b(c)d"
// Output: "ab(c)d"

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    s[i] = '$';
                }
                else
                {
                    st.pop();
                }
            }
        }

        while (!st.empty())
        {
            s[st.top()] = '$';
            st.pop();
        }

        s.erase(remove(s.begin(), s.end(), '$'), s.end());
        return s;
    }
};