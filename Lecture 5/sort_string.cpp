#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(string s, string s2)
{
    if (s.length() == s2.length())
        return s < s2;
    else
        return s.length() < s2.length();
}

int main()
{
    string s[100];
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }

    return 0;
}