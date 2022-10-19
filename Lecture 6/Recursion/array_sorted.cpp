#include <iostream>
using namespace std;

// checking through iterator
bool sorted3(int *a, int n, int i)
{
    // base case
    if (i == n - 1)
        return true;

    // rec case
    if (a[i] <= a[i + 1] and sorted3(a, n, i + 1))
        return true;
    else
        return false;
}

// checking from behind
bool sorted2(int *a, int n)
{
    // base case
    if (n <= 1)
    {
        return true;
    }

    // rec case
    if (a[n - 1] >= a[n - 2] and sorted2(a, n - 1))
        return true;

    else
        return false;
}

// checking from the start
bool sorted(int *a, int n)
{
    // base case
    if (n == 1 or n == 0)
    {
        return true;
    }

    // rec case
    if (a[0] <= a[1] and sorted(a + 1, n - 1))
        return true;

    else
        return false;
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

    if (sorted(a, n))
        cout << "Sorted" << endl;
    else
        cout << "Not Sorted" << endl;

    if (sorted2(a, n))
        cout << "Sorted" << endl;
    else
        cout << "Not Sorted" << endl;
    if (sorted3(a, n, 0))
        cout << "Sorted" << endl;
    else
        cout << "Not Sorted" << endl;

    return 0;
}