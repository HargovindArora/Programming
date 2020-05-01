// #include<bits/stdc++.h>
// using namespace std;

// class node{

//     public:
//         int data;
//         node *left;
//         node *right;

//         node(int d) : data(d), left(NULL), right(NULL){}
// };

// bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
//     {
//         return true;
//     }
//     return false;
// }

// int count(node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     return 1 + count(root->left) + count(root->right);
// }

// int sizeOfMaxBST(node *root)
// {
//     int maxSize = 0;
//     if (root == NULL)
//     {
//         return 0;
//     }
//     if (isBST(root))
//     {
//         maxSize = max(maxSize, count(root));
//     }
//     return max(maxSize, max(sizeOfMaxBST(root->left), sizeOfMaxBST(root->right)));
// }

// int main(){

//     int n;
//     cin >> n;
//     int pre[n];
//     for(int i=0; i<n; i++){
//         cin >> pre[i];
//     }
//     int ino[n];
//     for(int i=0; i<n; i++){
//         cin >> ino[i];
//     }
//     int count=0, maxm=0;
//     for(int i=1; i<n; i++){

//         if(ino[i]>ino[i-1]){
//             count++;
//             maxm = max(count, maxm);
//         }
//         else{
//             count = 0;
//         }
//     }

//     cout << maxm+1 << endl;

//     return 0;
// }

#include <bits/stdc++.h>
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

node *createTreeFromTrav(int *in, int *pre, int s, int e)
{
    static int i = 0;
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);

    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in, pre, s, index - 1);
    root->right = createTreeFromTrav(in, pre, index + 1, e);
    return root;
}
class Info
{
public:
    bool is_bst;
    int maxBSTsize;
    int leftmax;
    int rightmin;
    Info()
    {
        is_bst = true;
        maxBSTsize = 0;
        leftmax = INT_MIN;
        rightmin = INT_MAX;
    }
};

Info greatestBSTinBT(node *root)
{

    if (root == NULL)
    {
        return Info();
    }

    Info left = greatestBSTinBT(root->left);
    Info right = greatestBSTinBT(root->right);
    Info ans;
    if (root->data >= left.leftmax && root->data < right.rightmin &&
        left.is_bst && right.is_bst)
    {
        ans.maxBSTsize = left.maxBSTsize + right.maxBSTsize + 1;
        ans.is_bst = true;
        ans.leftmax = max(left.leftmax, root->data);
        ans.rightmin = min(right.rightmin, root->data);
    }
    else
    {
        ans.is_bst = false;
        ans.maxBSTsize = max(left.maxBSTsize, right.maxBSTsize);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int preOrder[10000], inOrder[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    node *root = createTreeFromTrav(inOrder, preOrder, 0, n - 1);

    cout << greatestBSTinBT(root).maxBSTsize;
    return 0;
}