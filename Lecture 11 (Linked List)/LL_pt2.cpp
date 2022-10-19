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

node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    node *c;

    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node *midpoint(node *head)
{
    node *fast = head->next;
    node *slow = head;

    while (!fast and !fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *mergesort(node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    // rec case
    node *mid = midpoint(head);

    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    a = mergesort(a);
    b = mergesort(b);

    return merge(a, b);
}

void print(node *h)
{
    while (h != NULL)
    {
        cout << h->data << "->";
        h = h->next;
    }
    cout << "NULL" << endl;
}

void BubbleSortLL(node *&head)
{
    int len = length(head);

    for (int i = 1; i <= len - 1; i++)
    {
        node *c = head, *p = NULL;
        while (c != NULL and c->next != NULL)
        {
            node *n = c->next;
            if (c->data > n->data)
            {
                if (p != NULL)
                {
                    c->next = n->next;
                    n->next = c;
                    p->next = n;
                    p = n;
                }
                else
                {
                    c->next = n->next;
                    n->next = c;
                    p = head = n;
                }
            }
            else
            {
                p = c;
                c = n;
            }
        }
    }
}
//////////////////////////////////////// BREAK CYCLE /////////////////////////////////////////////////

void breakCycle(node *head, node *fast)
{
    node *slow = head;
    node *temp = head;
    while (temp->next != fast)
    {
        temp = temp->next;
    }
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        temp = temp->next;
    }
    temp->next = NULL;
}

//////////////////////////////////////// BREAK CYCLE /////////////////////////////////////////////////

///////////////////////////////////////   CYCLE DETECTION   ////////////////////////////////////////////

bool isCyclic(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            // to break the cycle
            breakCycle(head, fast);
            return true;
        }
    }
    return false;
}

///////////////////////////////////////   CYCLE DETECTION   ////////////////////////////////////////////

void createCycle(node *head, node *tail)
{
    tail->next = head->next->next->next;
}

int main()
{
    node *head = NULL, *ht = NULL;

    push_back(head, ht, 6);
    push_back(head, ht, 8);
    push_back(head, ht, 1);
    push_back(head, ht, 2);
    push_back(head, ht, 3);
    push_back(head, ht, 7);
    push_back(head, ht, 5);

    // createCycle(head, ht);
    head = mergesort(head);

    // BubbleSortLL(head);

    // if (!isCyclic(head))
    //     print(head);

    // else
    //     cout << "LL is cyclic " << endl;

    print(head);

    return 0;
}