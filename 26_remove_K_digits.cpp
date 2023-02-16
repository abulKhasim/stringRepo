// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.


class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";

        stack<char> s;
        for(int i=0; i<num.size(); i++){
            if(s.empty()) s.push(num[i]);
            else{
                while(!s.empty() && s.top() > num[i] && k>0){
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
        }

        while(k>0){
            s.pop();
            k--;
        }

        if(s.empty()) return "0";

        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        // Removing leading zero 
        int i=0;
        while(ans[i] == '0'){
            i++;
        }

        return (ans.substr(i) == "")? "0" : ans.substr(i);
    }
};