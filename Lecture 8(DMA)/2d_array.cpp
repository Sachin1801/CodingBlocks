#include <iostream>
using namespace std;

int main()
{
    int rows, col;
    cin >> rows >> col;

    int **a = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        a[i] = new int[col];
    }

    int no = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            a[i][j] = no++;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << *(*(a + i) + j) << " "; // we can lso write normally like a[i][j];
        }
        cout << endl;
    }

    return 0;
}