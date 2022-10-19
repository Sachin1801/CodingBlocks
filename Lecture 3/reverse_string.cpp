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

void reverse_str(char a[])
{
    int i = 0;
    int j = length(a) - 1;
    while (i < j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
    return;
}

void print(char a[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    char a[100];
    cin.getline(a, 100);
    reverse_str(a);
    print(a);
    return 0;
}