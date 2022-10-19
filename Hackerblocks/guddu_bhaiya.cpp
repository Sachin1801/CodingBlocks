#include <iostream>
using namespace std;

void solve(char name[], int i, int j, int k)
{
    while (k--)
    {
        swap(name[i - 1], name[j - 1]);
        char temp = name[j - 1];
        for (int x = j - 1; x > i; x--)
        {
            name[x] = name[x - 1];
        }
        name[i] = temp;
    }
}

int main()
{
    char name[100000];
    cin >> name;
    int n, i, j, k;
    cin >> n;

    while (n--)
    {
        cin >> i >> j >> k;
        solve(name, i, j, k);
    }

    cout << name << endl;

    return 0;
}