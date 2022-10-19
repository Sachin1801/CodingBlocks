#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
    node *head;
    node *tail;
    int cs;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        cs = 0;
    }

    void push(int d)
    {
        if (!head)
        {
            head = tail = new node(d);
            cs++;
        }
        else
        {
            node *n = new node(d);
            tail->next = n;
            tail = n;
            cs++;
        }
    }

    void pop()
    {
        if (!head)
            return;
        else if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            cs--;
        }
        else
            (head != NULL)
            {
                node *temp = head;
                head = head->next;
                delete temp;
                cs--;
            }
    }

    bool empty()
    {
        return head == NULL;
    }

    int size()
    {
        return cs;
    }

    int front()
    {
        return head->data;
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

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}