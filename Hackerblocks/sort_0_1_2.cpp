#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int d) : data(d), next(NULL) {}
};

int length(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        head = head->next;
        ans++;
    }
    return ans;
}

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

void sortLL(node *head)
{
    int count[3] = {0, 0, 0};
    node *ptr = head;

    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }

    ptr = head;
    int i = 0;

    while (ptr != NULL)
    {
        if (count[i] == 0)
        {
            i++;
        }
        else
        {
            ptr->data = i;
            ptr = ptr->next;
            count[i]--;
        }
    }
    print(head);
}

int main()
{
    int n;
    cin >> n;
    node *head = NULL, *tail = NULL;
    while (n--)
    {
        int d;
        cin >> d;
        push_back(head, tail, d);
    }

    sortLL(head);

    // print(head);

    return 0;
}