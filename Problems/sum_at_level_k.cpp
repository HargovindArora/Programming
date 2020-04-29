#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

node *buildTree(node *root)
{
    int d, n;
    cin >> d >> n;
    root = new node(d);
    if (n == 0)
    {
        return root;
    }
    else if (n == 1)
    {
        root->left = buildTree(root->left);
        return root;
    }
    else
    {
        root->left = buildTree(root->left);
        root->right = buildTree(root->right);
        return root;
    }
}

void preOrder(node *root){

    if(root==NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}
int global_sum = 0;
void sumAtkthLevel(node *root, int k){

    if(root==NULL){
        return;
    }
    if(k==0){
        global_sum += root->data;
        return;
    }
    sumAtkthLevel(root->left, k-1);
    sumAtkthLevel(root->right, k-1);
    return;
}

int sumAtLevelK(node *root, int k)
{
    if (root == NULL)
        return 0;

    int ans = 0;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    bool flag = false;

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
            k--;
            if (flag)
                break;
            if (k == 0)
                flag = true;
        }
        else
        {
            if (flag)
                ans += f->data;
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }

    return ans;
}

int main(){
    node *root = NULL;
    root = buildTree(root);
    int k;
    cin >> k;
    
    sumAtkthLevel(root, k);
    cout << global_sum << endl;

    return 0;
}