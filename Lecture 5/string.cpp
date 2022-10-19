#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

int main()
{
    string s, s1;
    s = "Hello World";
    cout << s << endl;
    s1 = "Learning Coding.";
    cout << s1 << endl;
    s += s1;
    cout << s << endl;
    cout << s1 << endl;

    return 0;
}