#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s = "";
    s.push_back('A');
    s.push_back('B');
    s.push_back('C');
    s.push_back('D');

    cout << s << endl;

    s.pop_back();

    cout << s << endl;

    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        cout << s[i] << " ";
    }
    return 0;
}