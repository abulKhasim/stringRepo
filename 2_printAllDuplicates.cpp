#include <bits/stdc++.h>
using namespace std;

void printDuplicates(string s){

    unordered_map<char, int> mp;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
    }   

    for(auto i : mp){
        if(i.second > 1){
            cout << i.first << " " << i.second << endl;
        }
    }

}

int main(){

    string s = "amanaplanacanalPanama";
    printDuplicates(s);

    return 0;
}