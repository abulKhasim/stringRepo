class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int ans = 0;

        while (j < s.size())
        {
            mp[s[j]]++;

            if (mp.size() < k)
            {
                j++;
            }

            else if (mp.size() == k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if (ans == 0)
            return -1;
        return ans;
    }
};