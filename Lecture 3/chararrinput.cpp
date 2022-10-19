#include <iostream>
using namespace std;

void readString(char *a, int s, char delimiter)
{
    char ch;
    ch = cin.get();
    int i = 0;

    while (i < s - 1 and ch != delimiter)
    {
        a[i] = ch;
        i++;
        ch = cin.get();
    }
    a[i] = '\0';
}

int main()
{
    char a[100];

    readString(a, 100, '$');
    cout << a << endl;
    return 0;
}