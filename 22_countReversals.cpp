// Input:
// S = "}{{}}{{{"
// Output: 3
// Explanation: One way to balance is:
// "{{{}}{}}". There is no balanced sequence
// that can be formed in lesser reversals.

int countRev (string s)
{
    if(s.size() % 2 != 0) return -1;
    
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    
    int a = 0, b = 0;
    while(!st.empty()){
        if(st.top() == '{'){
            a++;
        }else{
            b++;
        }
        st.pop();
    }
    
    int ans = (a+1)/2 + (b+1)/2;
    
    return ans;
}