// String
class Solution
{
private:
    void solve(string S, vector<string> &ans, int index)
    {
        if (index >= S.size())
        {
            ans.push_back(S);
            return;
        }

        for (int j = index; j < S.size(); j++)
        {
            swap(S[index], S[j]);
            solve(S, ans, index + 1);
            swap(S[index], S[j]);
        }
    }

public:
    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        int index = 0;
        solve(S, ans, index);
        sort(ans.begin(), ans.end());

        // Removing duplicates from vector
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};



// Array
class Solution
{
private:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int j = index; j < nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            solve(nums, ans, index + 1);
            swap(nums[index], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};