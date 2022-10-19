#include <iostream>
using namespace std;

int binary_search(int a[], int s, int e, int key)
{
    // base case
    if (s > e)
    {
        return -1;
    }

    // rec case
    int mid = (s + e) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    else if (a[mid] < key)
    {
        return binary_search(a, mid + 1, e, key);
    }
    else
    {
        return binary_search(a, s, mid - 1, key);
    }
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
    sort(a, a + n);
    int key;
    cin >> key;
    cout << binary_search(a, 0, n - 1, key) << endl;

    return 0;
}