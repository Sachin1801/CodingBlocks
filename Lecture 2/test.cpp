#include <iostream>
using namespace std;

void mergesorted(int a[], int b[], int n, int m)
{
    int i = n - 1, j = m - 1, k = m + n - 1;
    while (i >= 0 and j >= 0)
    {
        if (a[i] > b[j])
        {
            a[k--] = a[i--];
        }
        else
        {
            a[k--] = b[j--];
        }
    }
    while (j >= 0)
    {
        a[k--] = b[j--];
    }
}

int main()
{
    int a[8] = {3, 4, 9, 11};
    int b[] = {1, 2, 8, 10};
    int n = 4, m = 4;
    mergesorted(a, b, n, m);
    for (auto x : a)
    {
        cout << x << " ";
    }

    return 0;
}