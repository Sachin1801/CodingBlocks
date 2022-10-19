#include <iostream>
using namespace std;

int min_denom(int n)
{
    vector<int> dp(n + 1, INT + MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min(dp[i - 1], min((i - 7) >= 0) ? dp[i - 7] : dp[])
    }
}

int main()
{
    int n;
    cin >> n;

    cout << min_denom(n) << endl;

    return 0;
}