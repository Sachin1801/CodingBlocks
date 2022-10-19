#include <iostream>
using namespace std;

void spiral_print(int a[][10], int r, int c)
{
    int sr = 0, er = r - 1, sc = 0, ec = c - 1;
    while (sr <= er and sc <= ec)
    {
        // 1.print sc from sr to er
        for (int i = sr; i <= er; i++)
        {
            cout << a[i][sc] << ", ";
        }
        sc++;
        // 2.print er from sc to ec
        for (int i = sc; i <= ec; i++)
        {
            cout << a[er][i] << ", ";
        }
        er--;
        if (sr <= er)
        {
            // 3. print ec from er to sr
            for (int i = er; i >= sr; i--)
            {
                cout << a[i][ec] << ", ";
            }
        }
        ec--;
        // 4. print sr from ec to sc
        if (sc <= ec)
        {
            for (int i = ec; i >= sc; i--)
            {
                cout << a[sr][i] << ", ";
            }
            sr++;
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