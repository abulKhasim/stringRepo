#include <iostream>
using namespace std;

bool areRotations(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    else
    {
        string concated = s1 + s1;
        if (concated.find(s2) != string::npos)
            return true;
        else
            return false;
    }
}