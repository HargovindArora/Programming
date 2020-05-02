#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node(int d) : data(d), left(NULL), right(NULL) {}
};

node *buildTree(){

    int n;
    cin >> n;

    if(n==-1){
        return NULL;
    }

    node *root = new node(n);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

vector<int> v;

void restoreBST(node *root, node *&first, node *&middle, node *&last, node *&prev){

    if(root){

        restoreBST(root->left, first, middle, last, prev);

        if(prev && (root->data < (prev)->data)){
            if(!first){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }

        prev = root;

        restoreBST(root->right, first, middle, last, prev);
    }
}

int main(){

    node *root = buildTree();
    node *first = NULL, *last = NULL, *middle = NULL, *prev;
    restoreBST(root, first, middle, last, prev);
    
    if(first && last){
        v.push_back(first->data);
        v.push_back(last->data);
        sort(v.begin(), v.end());
        cout << v[0] << " " << v[1] << endl;
        return 0;
    }
    if(first && middle){
        v.push_back(first->data);
        v.push_back(middle->data);
    }

    sort(v.begin(), v.end());
    cout << v[0] << " " << v[1] << endl;

    return 0;
}