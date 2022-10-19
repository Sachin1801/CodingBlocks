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

void push_front(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *n = new node(data);
        head = tail = n;
    }
    else
    {
        node *n = new node(data);
        n->next = head;
        head = n;
    }
}

void insert(node *&head, node *&tail, int data, int pos)
{
    if (pos == 0)
    {
        push_front(head, tail, data);
        return;
    }
    else if (pos == length(head))
    {
        push_back(head, tail, data);
    }
    else
    {
        node *n = new node(data);
        node *temp = head;
        while (pos != 1)
        {
            temp = temp->next;
            pos--;
        }
        n->next = temp->next;
        temp->next = n;
    }
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

// Delete Function
void deleteAtFront(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node *t = head;
        head = head->next;
        delete t;
    }
}

void deleteAtEnd(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = tail = NULL;
    }
    else if (head->next == tail)
    {
        head->next = NULL;
        tail = head;
    }
    else
    {
        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        temp->next = NULL;
        tail = temp;
    }
}

// Delete at the given pos
void deleteatmid(node *&head, node *&tail, int pos)
{
    if (pos == 0)
    {
        deleteAtFront(head, tail);
        return;
    }
    else if (pos >= length(head) - 1)
    {
        deleteAtEnd(head, tail);
        return;
    }
    node *temp = head;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    node *n = temp->next;
    temp->next = temp->next->next;
    delete n;
}

// Iterative way to reverse
void reverseLL(node *&head, node *&tail)
{
    node *prev = NULL, *curr = head, *temp;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    swap(head, tail);
}

// recursive way to rweverse a linkerd list
void recReverseHelper(node *curr, node *prev)
{
    // base case
    if (curr == NULL)
    {
        return;
    }

    node *n = curr->next;
    curr->next = prev;
    recReverseHelper(n, curr);
}

void recReverse(node *&head, node *&tail)
{
    recReverseHelper(head, NULL);
    swap(head, tail);
}

// To merge Sorted Linked List
node *mergeSortedLL(node *h1, node *h2)
{
    // base case
    if (h1 == NULL)
        return h2;

    if (h2 == NULL)
        return h1;

    // rec case
    node *nH;
    if (h1->data < h2->data)
    {
        nH = h1;
        nH->next = mergeSortedLL(h1->next, h2);
    }
    else
    {
        nH = h2;
        nH->next = mergeSortedLL(h1, h2->next);
    }

    return nH;
}

// Mid value of the linked list
node *mid(node *&head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *fast = head->next, *slow = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    node *head = NULL, *tail = NULL;

    push_front(head, tail, 1);
    push_front(head, tail, 2);
    push_front(head, tail, 3);
    push_front(head, tail, 4);
    push_front(head, tail, 5);
    push_back(head, tail, 0);
    insert(head, tail, 10, 3); // to insert in middle
    push_back(head, tail, -1);
    push_back(head, tail, -2);

    // cout << length(head) << endl;
    // print(head);

    // while (head)
    // {
    //     deleteAtFront(head, tail);
    //     print(head);
    // }

    // deleteatmid(head, tail, 9);
    // recReverse(head, tail);
    // print(head);

    node *a = NULL, *b = NULL, *at = NULL, *bt = NULL;
    push_back(a, at, 1);
    push_back(a, at, 4);
    push_back(a, at, 5);
    push_back(a, at, 8);
    push_back(a, at, 10);

    push_back(b, bt, 0);
    push_back(b, bt, 3);
    push_back(b, bt, 6);
    push_back(b, bt, 7);

    head = mergeSortedLL(a, b);
    print(head);
    cout << endl;

    node *m = mid(head);
    cout << m->data << endl;
    ;

    return 0;
}