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

bool check(char a[], char b[])
{
    int temp[26] = {0};
    int lena = length(a);
    int lenb = length(b);
    if (lena != lenb)
    {
        return false;
    }
    for (int i = 0; i < lena; i++)
    {
        temp[a[i] - 'a']++;
    }
    for (int j = 0; j < lenb; j++)
    {
        temp[b[j] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (temp[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char a[100];
    char b[100];
    cin.getline(a, 100);
    cin.getline(b, 100);
    if (check(a, b))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}