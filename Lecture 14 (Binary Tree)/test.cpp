#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left, *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *createTree()
{
    int d;
    cin >> d;
    // base case
    if (d == -1)
    {
        return NULL;
    }

    // rec case
    node *root = new node(d);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void preorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int countNodes(node *root)
{
    // base case
    if (!root)
        return 0;
    // rec case
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int height(node *root)
{
    // base case
    if (!root)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int diameter(node *root)
{
    if (!root)
        return 0;

    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}

pair<int, int> fastDiameter(node *root)
{
    pair<int, int> ans;
    if (!root)
    {
        ans.first = 0;
        ans.second = 0;
        return ans;
    }

    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);

    ans.first = max(left.first, right.first) + 1;
    int op1 = left.first + right.first;
    ans.second = max(op1, max(left.second, right.second));

    return ans;
}

node *search(node *root, int key)
{
    if (!root)
        return NULL;

    if (root->data == key)
    {
        return root;
    }
    node *ans = search(root->left, key);
    if (ans)
        return ans;
    return search(root->right, key);
}

int main()
{
    // input - 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    node *root = createTree();

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    cout << "Total Nodes: " << countNodes(root) << endl;
    cout << "Tree height: " << height(root) << endl;
    cout << "Diameter of Tree is : " << diameter(root) << endl;
    pair<int, int> ans = fastDiameter(root);

    cout << "Height of Tree is : " << ans.first << " and Diameter of Tree is: " << ans.second << endl;
    int key;
    cin >> key;
    node *a = search(root, key);
    if (a)
        cout << a->data << endl;
    else
        cout << "Not present\n";

    return 0;
}