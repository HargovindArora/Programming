#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insertInBst(node *root, int data)
{

    if (root == NULL)
    {
        return new node(data);
    }
    if (data <= root->data)
    {
        root->left = insertInBst(root->left, data);
    }
    else
    {
        root->right = insertInBst(root->right, data);
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

        root = insertInBst(root, d);
        cin >> d;
    }
    return root;
}

void breadthFirstSearch(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *val = q.front();
        if (val == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
            continue;
        }
        cout << val->data << " ";
        q.pop();
        if (val->left)
        {
            q.push(val->left);
        }
        if (val->right)
        {
            q.push(val->right);
        }
    }
    return;
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

bool search(node *root, int data)
{

    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

node *deleteInBst(node *root, int data)
{

    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = deleteInBst(root->left, data);
        return root;
    }
    else if (data == root->data)
    {

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        node *replace = root->right;
        while (replace->left != NULL)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBst(root->right, replace->data);
        return root;
    }
    else
    {
        root->right = deleteInBst(root->right, data);
        return root;
    }
}

bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX)
{

    if (root == NULL)
    {
        return true;
    }
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
    {
        return true;
    }
    else
    {
        return false;
    }
}

class LinkedList
{

public:
    node *head;
    node *tail;
};

LinkedList flatten(node *root)
{

    LinkedList l;
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }
    if (root->left == NULL && root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    if (root->left != NULL && root->right == NULL)
    {
        LinkedList leftll = flatten(root->left);
        leftll.tail->right = root;
        l.head = leftll.head;
        l.tail = root;
        return l;
    }
    if (root->left == NULL && root->right != NULL)
    {
        LinkedList rightll = flatten(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;
        return l;
    }
    LinkedList leftll = flatten(root->left);
    LinkedList rightll = flatten(root->right);
    leftll.tail->right = root;
    root->right = rightll.head;
    l.head = leftll.head;
    l.tail = rightll.tail;

    return l;
}

node *createTreeFromTraversal(int *ino, int *pre, int beg, int end)
{

    static int i = 0;
    if (beg > end)
    {
        return NULL;
    }
    node *root = new node(pre[i]);
    int index = -1;
    for (int j = beg; j <= end; j++)
    {
        if (ino[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(ino, pre, beg, index - 1);
    root->right = createTreeFromTraversal(ino, pre, index + 1, end);

    return root;
}

int main()
{

    // node *root = build();
    // breadthFirstSearch(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;

    // int s;
    // cin >> s;
    // root = deleteInBst(root, s);
    // inorder(root);

    // if(isBST(root)){
    //     cout << "It is a BST\n";
    // }
    // else{
    //     cout << "Not a BST\n";
    // }

    // LinkedList l = flatten(root);
    // node *temp = l.head;
    // while(temp!=NULL){
    //     cout << temp->data << "-->";
    //     temp = temp->right;
    // }
    // cout << endl;
    int pre[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int ino[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(ino) / sizeof(int);
    node *root = createTreeFromTraversal(ino, pre, 0, n - 1);
    breadthFirstSearch(root);

    return 0;
}