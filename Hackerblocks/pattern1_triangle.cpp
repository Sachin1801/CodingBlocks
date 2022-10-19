#include <iostream>
using namespace std;

void print(int n, int i)
{
    // base case
    if (i > n)
    {
        return;
    }
    // rec case
    int j = 1;
    while (j <= i)
    {
        cout << "*\t";
        j++;
    }
    cout << endl;
    print(n, i + 1);
}

int main()
{
    int n;
    cin >> n;
    print(n, 1);
    return 0;
}