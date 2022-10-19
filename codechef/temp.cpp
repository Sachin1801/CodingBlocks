void solve(vector<int> &nums, vector<int> &out, int idx)
{
    ans.push_back(out);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i > idx and nums[i] == nums[i - 1])
        {
            continue;
        }
        out.push_back(nums[i]);
        solve(nums, out, i + 1);
        out.pop_back();
    }
}
