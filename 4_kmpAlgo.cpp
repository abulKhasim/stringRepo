#include <bits/stdc++.h>
using namespace std;

// Search Pattern
vector<int> kmp(string str, string pat)
{
    vector<int> pi(pat.size(), 0);

    for (int i = 1; i < pat.size(); i++)
    {
        int j = pi[i - 1];

        while (j > 0 && pat[j] != pat[i])
        {
            j = pi[j - 1];
        }

        if (pat[j] == pat[i])
        {
            j++;
        }

        pi[i] = j;
    }

    int n = str.size();
    int m = pat.size();
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n)
    {
        if (pat[j] == str[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            ans.push_back(i - (m - 1));
            j = pi[j - 1];
        }
        else if (pat[j] != str[i])
        {
            if (j == 0)
                i++;
            j = pi[j - 1];
        }
    }

    return ans;
}

int main()
{
    string str = "batmanandrobinarebat";
    string pat = "bat";

    vector<int> ans = kmp(str, pat);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}