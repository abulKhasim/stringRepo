#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
        
        int d, c, e;
        c = s.size();

        for(int i=0; i<c; i++){
            if(s[i] >= 97 && s[i] <= 122){
                s[i] = char(s[i] - 32);
            }
        }

        d = 0, c = s.size()-1, e = 0;

        while(1){
            if( (s[d] != ' ' && s[c] != ' ') && 
            (((s[c] >= 65) && (s[c] <= 90)) || ((s[c] >= 48) && (s[c] <= 57))) && 
            (((s[d] >= 65) && (s[d] <= 90)) || ((s[d] >= 48) && (s[d] <= 57))) ){
                if(s[c] != s[d]){
                    return false;
                    break;
                }
                d++; 
                c--;
            }
            else{
                if( (s[c] >= 0 && s[c] <= 47) || (s[c] >= 58 && s[c] < 65) || s[c] > 90){
                    c--;
                }
                if( (s[d] >= 0 && s[d] <= 47) || (s[d] >= 58 && s[d] < 65) || s[d] > 90){
                    d++;
                }
            }
            if(c<=d){
                break;
            }
        }

        return true;
    }

int main(){

    string s = "A man, a plan, a canal: Panama";
    bool ans = isPalindrome(s);
    cout << ans << endl;


}