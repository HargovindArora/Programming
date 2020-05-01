#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node(int x) : data(x), left(NULL), right(NULL) {}
};

node *createTreeFromTraversal(int *ino, int *pre, int beg, int end){

    static int i=0;
    if(beg>end){
        return NULL;
    }
    node *root = new node(pre[i]);
    int index = -1;
    for(int j=beg; j<=end; j++){

        if(ino[j]==pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(ino , pre, beg, index-1);
    root->right = createTreeFromTraversal(ino, pre, index+1, end);
    return root;
}

int main(){

    int n;
    cin >> n;
    int pre[n];
    for(int i=0; i<n; i++){
        cin >> pre[i];
    }
    int ino[n];
    for(int i=0; i<n; i++){
        cin >> ino[i];
    }
    int t;
    cin >> t;

    while(t--){

        int value, k;
        cin >> value >> k;



    }

    return 0;
}