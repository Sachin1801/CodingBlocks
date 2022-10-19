#include <iostream>
using namespace std;

const string a[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void convert(int n)
{
    // base case
    if (n / 10 == 0)
    {
        cout << a[n] << " ";
        return;
    }

    // rec case
    int temp = n % 10;
    convert(n / 10);
    cout << a[temp] << " ";
    return;
}

int main()
{
    int n;
    cin >> n;

    convert(n);

    return 0;
}