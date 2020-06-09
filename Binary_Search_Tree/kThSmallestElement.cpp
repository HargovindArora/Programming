#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node
{

public:
    int data;
    node *left, *right;

    node(int d) : data(d), left(NULL), right(NULL) {}
};

node *insertInBST(node *root, int data)
{

    if (root == NULL)
    {
        return new node(data);
    }
    if (data <= root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node *build()
{

    int d;
    cin >> d;
    node *root = NULL;

    while (d != -1)
    {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

int ans = 0;

void traverseInOrder(node *root, int &k)
{

    if (root == NULL)
    {
        return;
    }
    traverseInOrder(root->left, k);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    traverseInOrder(root->right, k);
}

int kThSmallest(node *root, int k)
{
    traverseInOrder(root, k);
    return ans;
}

int main()
{

    node *root = build();
    int x = kThSmallest(root, 4);
    cout << x << endl;

    return 0;
}