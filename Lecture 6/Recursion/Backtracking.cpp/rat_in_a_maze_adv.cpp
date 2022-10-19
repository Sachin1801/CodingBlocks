#include <iostream>
using namespace std;

void print(int sol[][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int a[][10], int row, int col, int i, int j, int sol[][10])
{
    if (i == row - 1 and j == col - 1)
    {
        sol[i][j] = 1;
        print(sol, row, col);
        return true;
    }

    // rec case
    sol[i][j] = 1;
    // moving down
    if (i + 1 < row and a[i + 1][j] != 9 and sol[i + 1][j] != 1)
    {
        bool down = check(a, row, col, i + 1, j, sol);
        if (down)
            return true;
    }

    if (j + 1 < col and a[i][j + 1] != 9 and sol[i][j + 1] != 1)
    {
        bool right = check(a, row, col, i, j + 1, sol);
        if (right)
            return true;
    }

    if (i - 1 >= 0 and a[i - 1][j] != 9 and sol[i - 1][j] != 1)
    {
        bool up = check(a, row, col, i - 1, j, sol);
        if (up)
            return true;
    }

    if (j - 1 >= 0 and a[i][j - 1] != 9 and sol[i][j - 1] != 1)
    {
        bool left = check(a, row, col, i, j - 1, sol);
        if (left)
            return true;
    }

    sol[i][j] = 0;
    return false;
}

int main()
{
    int row, col;
    cin >> row >> col;
    int board[10][10];
    char temp;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> temp;
            if (temp == 'X')
            {
                board[i][j] = 9;
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    int sol[10][10] = {0};

    check(board, row, col, 0, 0, sol);

    return 0;
}