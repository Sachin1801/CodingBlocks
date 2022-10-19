#include <iostream>
using namespace std;

int main()
{
    int *a = new int;
    *a = 10;
    cout << *a << endl;

    float *f = new float;

    *f = 10.11;
    cout << *f << endl;

    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}