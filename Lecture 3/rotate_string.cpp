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

void copy(char *a, char *b)
{
    int i = 0;
    while (b[i] != '\0')
    {
        a[i] = b[i];
        i++;
    }
}

void print(char a[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void rotate_str(char a[], int n)
{
    int len = length(a);
    for (int i = len - 1; i >= 0; i--)
    {
        a[i + n] = a[i];
    }
    int j = 0;
    int i = len;
    while (j < n)
    {
        a[j] = a[i];
        j++;
        i++;
    }
    a[len] = '\0';
}

int main()
{
    int n;
    cin >> n;
    cin.get();
    char a[100];
    cin.getline(a, 100);
    rotate_str(a, n % length(a));
    print(a);

    return 0;
}