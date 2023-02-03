#include <bits/stdc++.h>
using namespace std;

bool kmpAlgo(string str, string pat){

    vector<int> lps(pat.size(),0);

    for(int i=1; i<pat.size(); i++){
        int j = lps[i-1];

        while(j>0 && pat[j] != pat[i]){
            j = lps[j-1];
        }

        if(pat[j] == pat[i]) j++;

        lps[i] = j;
    }

    int n = str.size();
    int m = pat.size();
    int i=0;
    int j=0;
    vector<int> ans;

    while(i<n){
        if(pat[j] == str[i]){
            i++;
            j++;
        }

        if(j==m){
            return true;
            // ans.push_back(i-(m-1));
        }
        else if(pat[j] != str[i]){
            if(j==0) i++;
            j = lps[j-1];
        }
    }

    return false;

}

int main(){

    string str = "batmanandrobinarebat";
    string pat = "nare";

    bool ans  = kmpAlgo(str, pat);
    cout << ans << endl;


    return 0;
}