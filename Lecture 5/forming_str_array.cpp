#include <iostream>
using namespace std;

int main()
{
    string s[100];
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}