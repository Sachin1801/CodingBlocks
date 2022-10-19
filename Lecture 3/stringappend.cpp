#include <iostream>
using namespace std;

int length(char *a)
{
    int cnt = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        cnt++;
    }
    return cnt;
}

void append(char *a, char *b)
{
    int lena = length(a);
    int lenb = length(b);

    int i = lena;
    int j = 0;
    while (j <= lenb)
    {
        a[i++] = b[j++];
    }
}

int main()
{
    char a[100] = {"Hello"};
    char b[100] = {"World"};

    cout << a << endl;
    cout << b << endl;

    append(a, b);
    cout << a << endl;
    return 0;
}