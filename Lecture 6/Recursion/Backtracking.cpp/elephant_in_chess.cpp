#include <iostream>
using namespace std;

int elephantways(int i, int j)

{
    if (i == 0 and j == 0)
    {
        return 1;
    }

    int ans = 0;

    for (int k = 0; k < i; k++)
    {
        ans += elephantways(k, j);
    }

    for (int k = 0; k < j; k++)
    {
        ans += elephantways(i, k);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;

    cout << elephantways(n, m) << endl;

    return 0;
}