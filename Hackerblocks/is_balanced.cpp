#include <iostream>
#include <stack>
using namespace std;

char findopening(char s)
{
    if (s == ']')
        return '[';
    else if (s == '}')
        return '{';
    else if (s == ')')
        return '(';
    return -1;
}

int main()
{
    char a[1000000];
    cin.getline(a, 1000000, '\n');
    int n = strlen(a);
    stack<char> s;
    if (a[0] == '}' or a[0] == ']' or a[0] == ')')
        cout << "false" << endl;
    if (n == 0)
        cout << "true" << endl;
    if (n == 1)
        cout << "false" << endl;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '{' or a[i] == '[' or a[i] == '(')
        {
            s.push(a[i]);
        }
        else if (a[i] == '}' or a[i] == ']' or a[i] == ')')
        {
            char opening = findopening(a[i]);
            if (s.top() != opening)
            {
                flag = false;
                break;
            }
            else if (s.top() == opening)
            {
                s.pop();
            }
        }
    }
    if (flag == false)
    {
        cout << "false" << endl;
    }
    if (flag == true and s.empty())
    {
        cout << "true" << endl;
    }
    return 0;
}