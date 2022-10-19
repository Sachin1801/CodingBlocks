#include <iostream>
using namespace std;

void printpair(int a[], int n, int key)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] + a[i] == key)
            {
                cout << "(" << a[i] << "," << a[j] << ")" << endl;
            }
        }
    }
    return;
}

int main()
{
    int a[] = {1, 3, 2, 2, 0, 4};
    int n = sizeof(a) / sizeof(int);
    int key = 4;

    printpair(a, n, key);

    return 0;
}