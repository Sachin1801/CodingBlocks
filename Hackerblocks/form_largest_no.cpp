
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

bool myCompare(int x, int y)
{

    int xy = x, yx = y;

    int countx = 0, county = 0;

    // Count length of X
    while (x > 0)
    {
        countx++;
        x /= 10;
    }

    // Count length of Y
    while (y > 0)
    {
        county++;
        y /= 10;
    }

    x = xy;
    y = yx;

    while (countx--)
        yx *= 10;

    while (county--)
        xy *= 10;

    // Append x to y
    yx += x;

    // Append y to x
    xy += y;

    return xy > yx;
}

void printLargest(vector<ll> arr)
{

    sort(arr.begin(), arr.end(), myCompare);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }

    cout << endl;
}

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        printLargest(arr);
    }

    return 0;
}
