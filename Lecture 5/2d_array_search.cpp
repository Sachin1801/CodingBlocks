#include <iostream>
using namespace std;

void array_search(int key, int r, int c, int a[10][10])
{
    bool flag = false;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == key)
            {
                flag = true;
                cout << i << " " << j << endl;
            }
        }
    }
    if (flag == false)
    {
        cout << -1 << " " << -1 << endl;
    }
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
    int key;
    cin >> key;
    array_search(key, r, c, a);
    return 0;
}