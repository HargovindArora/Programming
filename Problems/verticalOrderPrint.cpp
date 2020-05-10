#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

class node {

    public:

        int data;
        node *left;
        node *right;

        node(int d) : data(d), left(NULL), right(NULL) {}
};

node *createTree(){

    queue<node*> q;
    int n;
    cin >> n;
    if(n==-1){
        return NULL;
    }
    node *root = new node(n);
    q.push(root);
    while(!q.empty()){

        node *temp = q.front();
        q.pop();
        cin >> n;
        if(n==-1){
            cin >> n;
        }
        else{
            temp->left = new node(n);
            q.push(temp->left);
            cin >> n;
        }
        if(n==-1){
            continue;
        }
        temp->right = new node(n);
        q.push(temp->right);

    }
    return root;
}

void verticalOrderPrint(node *root, int d, map<int, vector<int>> &m){

    if(root==NULL){
        return;
    }
    m[d].push_back(root->data);
    verticalOrderPrint(root->left, d-1, m);
    verticalOrderPrint(root->right, d+1, m);
    return;
}

int main(){

    int k;
    cin >> k;
    node *root = createTree();
    map<int, vector<int>> m;
    verticalOrderPrint(root, 0, m);
    for(auto x:m){
        for(int y:x.second){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}