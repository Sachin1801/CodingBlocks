#include <iostream>
#include <cstring>
using namespace std;

int string_to_int(string s, int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    // rec case
    int ld = s[n - 1] - '0';
    int ca = string_to_int(s, n - 1);
    return ca * 10 + ld;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    cout << string_to_int(s, n) << endl;

    return 0;
}