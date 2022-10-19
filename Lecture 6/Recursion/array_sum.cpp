#include <iostream>
using namespace std;

int arr_sum(int *a, int n)
{
    if (n == 0)
    {
        return 0;
    }

    // rec case
    return a[0] + arr_sum(a + 1, n - 1);
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << arr_sum(a, n) << endl;

    return 0;
}