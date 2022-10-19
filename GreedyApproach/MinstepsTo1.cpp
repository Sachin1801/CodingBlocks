#include <iostream>
#include <vector>
using namespace std;

int dp[100000];

// int minStepsTo1(int n)
// {
//     // base case
//     if (n == 1)
//     {

//         return 0;
//     }

//     // rec case
//     int op1, op2, op3;
//     op1 = op2 = op3 = INT_MAX;

//     op1 = minStepsTo1(n - 1);

//     if (n % 2 == 0)
//     {
//         op2 = minStepsTo1(n / 2);
//     }
//     if (n % 3 == 0)
//     {
//         op3 = minStepsTo1(n / 3);
//     }

//     return min(op1, min(op2, op3)) + 1;
// }

int topdown(int n)
{
    // base case
    if (n == 1)
    {
        return dp[n] = 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // rec case
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    op1 = topdown(n - 1);

    if (n % 2 == 0)
    {
        op2 = topdown(n / 2);
    }
    if (n % 3 == 0)
    {
        op3 = topdown(n / 3);
    }

    return dp[n] = min(op1, min(op2, op3)) + 1;
}

int bottomUp(int n)
{
    vector<int> dp(n + 1, 0);
    // for (int i = 2; i <= n; i++)
    // {
    //     int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    //     op1 = dp[i - 1];
    //     if (i % 2 == 0)
    //         op2 = dp[i / 2];
    //     if (i % 3 == 0)
    //         op3 = dp[i / 3];

    //     dp[i] = min(op1, min(op2, op3)) + 1;
    // }

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1], min(i % 2 == 0 ? dp[i / 2] : INT_MAX, i % 3 == 0 ? dp[i / 3] : INT_MAX)) + 1;
    }

    return dp[n];
}

int main()
{
    int dp[100000];
    for (int i = 0; i < 100000; i++)
    {
        dp[i] = -1;
    }
    cout << bottomUp(1000) << endl;
    cout << topdown(1000) << endl;

    return 0;
}