#include <iostream>
using namespace std;

void bubble_sort(int a[], int n, int j)
{
    // base case
    if (n == 1)
    {
        return;
    }

    // rec case
    while (j < n - 1)
    {
        if (a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
        }
        j++;
    }
    bubble_sort(a, n - 1, 0);
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
    bubble_sort(a, n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}