#include <iostream>
#include <algorithm>
using namespace std;

int rs1 = -1, rs2 = -1;

void roses(int a[], int n, int key)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[i] + a[j] == key)
        {
            rs1 = a[i];
            rs2 = a[j];
            i++;
            j--;
        }
        else if (a[i] + a[j] < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "Deepak should buy roses whose prices are " << rs1 << " and " << rs2 << endl;
    rs1 = -1;
    rs2 = -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int key;
        cin >> key;
        sort(a, a + n);
        roses(a, n, key);
    }

    return 0;
}