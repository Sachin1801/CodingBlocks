#include <iostream>
using namespace std;

void wave_print(int a[][10], int r, int c)
{
    int i, j;
    for (i = 0; i < c; i++)
    {
        if (i % 2 == 0)
        {
            for (j = 0; j < r; j++)
            {
                cout << a[j][i] << ", ";
            }
        }
        else
        {
            for (j = r - 1; j >= 0; j--)
            {
                cout << a[j][i] << ", ";
            }
        }
    }
    return;
}

int main()
{
    int r, c;
    cin >> r >> c;
    int a[10][10];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    wave_print(a, r, c);
    return 0;
}