#include <iostream>
using namespace std;

class Queue
{
    int *a, ms, cs, front, end;

public:
    Queue(int default_size = 5)
    {
        a = new int[default_size];
        ms = default_size;
        cs = 0;
        front = 0;
        end = ms - 1;
    }

    bool full()
    {
        return cs == ms;
    }

    bool empty()
    {
        return cs == 0;
    }

    void push(int data)
    {
        if (!full())
        {
            end = (end + 1) % ms;
            a[end] = data;
            cs++;
        }
        else
            cout << "Overflow\n";
    }

    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % ms;
            cs--;
        }
        else
            cout << "Underflow\n";
    }

    int Front()
    {
        return a[front];
    }

    int size()
    {
        return cs;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while (!q.empty())
    {
        cout << q.Front() << " ";
        q.pop();
    }

    return 0;
}