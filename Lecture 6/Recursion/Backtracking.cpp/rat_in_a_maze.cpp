#include <iostream>
using namespace std;

void print(int a[][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int a[][4], int n, int m, int i, int j)
{
    // base check
    if (i == n - 1 and j == m - 1)
    {
        a[i][j] = 1;
        print(a, n, m);
        cout << "\n\n";
        return false;
    }

    // rec case
    // 1. supposing we are starting from right
    a[i][j] = 1;

    if (i + 1 < n and a[i + 1][j] != 9)
    {
        bool downway = check(a, n, m, i + 1, j);
        if (downway) // if the rat is moving on the downward direction
        {
            return true;
        }
    }

    if (j + 1 < m and a[i][j + 1] != 9)
    {
        bool rightway = check(a, n, m, i, j + 1);
        if (rightway)
        {
            return true;
        }
    }

    a[i][j] = 0;
    return false;
}

int main()
{

    int a[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 9, 9},
        {0, 0, 0, 0},
        {9, 9, 0, 0}};
    int n = 4, m = 4;

    if (check(a, n, m, 0, 0))
        cout << "Yes we can reach cheese" << endl;
    else
        cout << "No we cannot reach the cheese" << endl;

    return 0;
}