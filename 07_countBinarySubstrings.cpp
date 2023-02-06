int countBinarySubstrings(string s)
{
    int curr = 1, prev = 0, sum = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            curr++;
        }
        else
        {
            sum += min(curr, prev);
            prev = curr;
            curr = 1;
        }
    }
    sum += min(curr, prev);

    return sum;
}