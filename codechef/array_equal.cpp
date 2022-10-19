
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int maxe = 0;
        unordered_map<int, int> m;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
            maxe = max(maxe, m[a[i]]);
        }
        int temp = (n / 2) + 1;
        cout << temp;
        if (temp < maxe)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}