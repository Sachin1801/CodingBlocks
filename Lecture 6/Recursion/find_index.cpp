#include <iostream>
using namespace std;

// print all occurences
void all_occ(int *a, int n, int key, int i)
{
    // base case
    if (i == n)
    {
        return;
    }

    // rec case
    if (a[i] == key)
    {
        cout << i << " ";
    }
    all_occ(a, n, key, i + 1);
    return;
}

// print last occ
int last_occ(int *a, int n, int key)
{
    if (n == 0)
    {
        return -1;
    }

    if (a[n - 1] == key)
    {
        return n - 1;
    }
    return last_occ(a, n - 1, key);
}

int first_occ(int *a, int n, int key, int i)
{
    // base case
    if (i == n)
    {
        return -1;
    }
    if (a[i] == key)
    {
        return i;
    }

    // rec case
    return first_occ(a, n, key, i + 1);
}

bool check(int *a, int n, int key, int i)
{
    // base case
    if (i == n)
    {
        return false;
    }

    // rec case
    if (a[i] == key)
    {
        return true;
    }
    return check(a, n, key, i + 1);
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
    int key;
    cin >> key;

    if (check(a, n, key, 0))
        cout << "Present" << endl;
    else
        cout << "Not Present" << endl;

    cout << first_occ(a, n, key, 0) << endl;
    cout << last_occ(a, n, key) << endl;
    all_occ(a, n, key, 0);
    cout << endl;
    return 0;
}