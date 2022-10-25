#include <iostream>
#include <vector>
using namespace std;

int n_stairs(int n, int k, int *dp)
{
    // base case
    if (n == 0)
        return dp[n] = 1;

    if (n < 0)
        return 0;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += n_stairs(n - i, k, dp);
    }

    return dp[n] = ans;
}

int N_stairs_2(int n, int k)
{
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0 and dp[i - j] != -0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int dp[100000];
    memset(dp, -1, sizeof dp);

    cout << n_stairs(n, k, dp) << endl;
    cout << N_stairs_2(n, k);

    return 0;
}