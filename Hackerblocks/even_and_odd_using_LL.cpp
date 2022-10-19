#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int d) : data(d), next(NULL) {}
};

void push_back(node *&head, node *&tail, int d)
{
    if (!head)
    {
        head = tail = new node(d);
    }
    else
    {
        node *n = new node(d);
        tail->next = n;
        tail = n;
    }
}

void print(node *h)
{
    while (h != NULL)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << " " << endl;
}

int main()
{
    int n;
    cin >> n;
    node *headeven = NULL, *taileven = NULL, *headodd = NULL, *tailodd = NULL;
    while (n--)
    {
        int d;
        cin >> d;
        if (d % 2 == 0)
        {
            push_back(headeven, taileven, d);
        }
        else
        {
            push_back(headodd, tailodd, d);
        }
    }

    if (headodd == NULL and headeven)
    {
        print(headeven);
    }
    else
    {
        tailodd->next = headeven;
        print(headodd);
    }

    return 0;
}