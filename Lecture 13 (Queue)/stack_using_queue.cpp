#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    bool empty()
    {
        return q1.empty() and q2.empty();
    }

    void push(int x)
    {
        if (!q1.empty())
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }

    void pop()
    {
        if (q1.empty())
        {
            while (!q2.empty())
            {
                int front = q2.front();
                q2.pop();

                if (q2.empty())
                    break;

                q1.push(front);
            }
        }
        else
        {
            while (!q1.empty())
            {
                int front = q1.front();
                q1.pop();

                if (q1.empty())
                    break;

                q2.push(front);
            }
        }
    }

    int top()
    {
        if (q1.empty())
        {
            while (!q2.empty())
            {
                int front = q2.front();
                q2.pop();

                q1.push(front);
                if (q2.empty())
                    return front;
            }
        }
        else
        {
            while (!q1.empty())
            {
                int front = q1.front();
                q1.pop();
                q2.push(front);

                if (q1.empty())
                    return front;
            }
        }
    }
};

int main()
{
    Stack s;
    // if (!s.empty())
    // {
    //     cout << s.top();
    // }
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
