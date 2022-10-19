#include <iostream>
#include <stack>
using namespace std;

void InsertAtBottom(stack<int> &s, int data)
{
    // base case
    if (s.empty())
    {
        s.push(data);
        return;
    }
    // rec case
    int t = s.top();
    s.pop();
    InsertAtBottom(s, data);
    s.push(t);
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int t = s.top();
    s.pop();
    reverse(s);
    InsertAtBottom(s, t);
}

void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);

    reverse(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}