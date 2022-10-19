#include <iostream>
#include <set>
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
    node *head = NULL, *tail = NULL;
    int d;
    cin >> d;
    push_back(head, tail, d);
    int a[100000] = {0};
    a[d]++;
    while (d != -1)
    {
        cin >> d;
        if (a[d] != 1)
        {
            push_back(head, tail, d);
            a[d]++;
        }
        else
        {
            node *temp = head;
            while ((temp->next)->data != d)
            {
                temp = temp->next;
            }
            tail->next = temp;
            break;
        }
    }
    while (d != -1)
    {
        cin >> d;
    }

    isCyclic(head);

    print(head);
    return 0;
}