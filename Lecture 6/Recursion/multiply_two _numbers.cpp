#include <iostream>
using namespace std;

int multiply(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    // base case
    if (n == 1)
    {
        return m;
    }
    int ans = m + multiply(m, n - 1);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << multiply(m, n) << endl;

    return 0;
}