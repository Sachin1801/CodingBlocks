#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int minchange(vector<int> denom, int amt, vector<int> &dp)
{
    // base case
    if (amt == 0)
    {
        return dp[amt] = 0;
    }

    if (dp[amt] != -1)
    {
        return dp[amt];
    }

    // rec case
    int ans = INT_MAX;
    for (int i = 0; i < denom.size(); i++)
    {
        if (amt >= denom[i])
        {
            int choti_amt = amt - denom[i];
            int x = minchange(denom, choti_amt, dp);
            if (x != INT_MAX)
            {
                ans = min(ans, x + 1);
            }
        }
    }
    return dp[amt] = ans;
}

// bottom up
int mincoinexchange2(vector<int> denom, int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;

        for (auto c : denom)
        {
            if (i - c >= 0 and dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main()
{
    vector<int> denom = {1, 7, 10, 20, 30};
    // int dp[100000];
    // memset(dp, -1, sizeof(dp));
    // for (int i = 0; i < sizeof(dp); i++)
    // {
    //     dp[i] = -1;
    // }
    int amt;
    cin >> amt;
    vector<int> dp(amt + 1, -1);
    cout << minchange(denom, amt, dp) << endl;

    cout << mincoinexchange2(denom, amt) << endl;

    return 0;
}