#include <iostream>
#include <cstring>
using namespace std;

int string_to_int(string s, int n, int i)
{
    // base case
    if (n == 1)
    {
        return s[0] * i;
    }
    // rec case
    int cp = (s[n - 1] - '0') * i;
    int bp = string_to_int(s, n - 1, i * 10);

    return cp + bp;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    cout << string_to_int(s, n, 1) << endl;

    return 0;
}