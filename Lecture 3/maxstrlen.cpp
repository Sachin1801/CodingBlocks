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

int main()
{
    int n;
    cin >> n;
    char ans[100];
    int max = 0;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        char ch[100];
        cin.getline(ch, 100);
        int len = length(ch);
        if (len > max)
        {
            copy(ans, ch);
            max = len;
        }
    }
    cout << ans << endl;
    cout << length(ans) << endl;
    return 0;
}