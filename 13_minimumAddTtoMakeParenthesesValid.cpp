// Input: s = "())"
// Output: 1

// Input: s = "((("
// Output: 3

// Input: s = "()))(("
// Output: 4


class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    count++;
                }
            }
        }

        count += st.size();
        return count;
    }
};