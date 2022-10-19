#include <iostream>
using namespace std;

void spiral_print(int a[][10], int r, int c)
{
    int sr = 0, er = r - 1, sc = 0, ec = c - 1;
    while (sr <= er and sc <= ec)
    {
        // 1.print sr from sc to sc
        for (int i = sc; i <= ec; i++)
        {
            cout << a[sr][i] << ", ";
        }
        sr++;
        // 2.print ec from sr to er
        for (int i = sr; i <= er; i++)
        {
            cout << a[i][ec] << ", ";
        }
        ec--;
        if (sr <= er)
        {
            // 3. print er from ec to sc
            for (int i = ec; i >= sc; i--)
            {
                cout << a[er][i] << ", ";
            }
        }
        er--;
        // 4. print sc from er to sr
        if (sc <= ec)
        {
            for (int i = er; i >= sr; i--)
            {
                cout << a[i][sc] << ", ";
            }
            sc++;
        }
    }
    cout << "END" << endl;
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
    spiral_print(a, r, c);
    return 0;
}