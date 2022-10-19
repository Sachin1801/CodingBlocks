#include <iostream>
using namespace std;

void subsequences(char a[], int i)
{
    // base case
    if (a[i] == '\0')
    {
        cout << a << endl;
        return;
    }

    for (int j = i; a[j] != '\0'; j++)
    {
        swap(a[i], a[j]);
        subsequences(a, i + 1);
        // backtracking
        swap(a[i], a[j]);
    }
}

int main()
{
    char a[100];
    cin >> a;
    subsequences(a, 0);

    return 0;
}