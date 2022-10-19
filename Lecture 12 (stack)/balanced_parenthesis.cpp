#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(char *a)
{
    stack<char> s;

    for (int i = 0; a[i] != '\0'; i++)
    {
        char ch = a[i];

        switch (ch)
        {
        case '{':
        case '(':
        case '[':
            s.push(ch);
            break;

        case '}':
            if (s.empty() || s.top() != '{')
                return false;

            s.pop();
            break;

        case ']':
            if (s.empty() || s.top() != '[')
                return false;

            s.pop();
            break;

        case ')':
            if (s.empty() || s.top() != '(')
                return false;

            s.pop();
                }
    }
    if (s.empty())
        return true;
    else
        return false;
}

int main()
{

    char a[] = "{a+[b+(c+d)]*e}";

    if (isBalanced(a))
        cout << "Yes Balanced" << endl;

    else
        cout << "Not balanced" << endl;

    return 0;
}