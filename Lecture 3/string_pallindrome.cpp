#include <iostream>
using namespace std;

bool isPallindrome(char *a, int n)
{
    int i = 0;
    int j = n;
    while (i < j)
    {
        if (a[i] != a[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    char ch[] = "NITIN";
    int n = sizeof(ch) / sizeof(char);
    if (isPallindrome(ch, n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}