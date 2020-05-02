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
vector<int> v;
void printKdistanceNodeDown(node *root, int k){

    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        v.push_back(root->data);
        return;
    }
    printKdistanceNodeDown(root->left, k-1);
    printKdistanceNodeDown(root->right, k-1);

}

int printKDistanceNodes(node *root, int value, int k){

    if(root==NULL){
        return -1;
    }
    if(root->data==value){
        printKdistanceNodeDown(root, k);
        return 0;
    }

    int left = printKDistanceNodes(root->left, value, k);
    if(left!=-1){
        if(left+1==k){
            v.push_back(root->data);
        }
        else{
            printKdistanceNodeDown(root->right, k-left-2);
        }
        return 1+left;
    }

    int right = printKDistanceNodes(root->right, value, k);
    if(right!=-1){
        if(right+1==k){
            v.push_back(root->data);
        }
        else{
            printKdistanceNodeDown(root->left, k-right-2);
        }
        return 1+right;
    }

    return -1;
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
    node *root = createTreeFromTraversal(ino, pre, 0, n-1);
    int t;
    cin >> t;

    while(t--){

        int value, k;
        cin >> value >> k;
        v.clear();
        printKDistanceNodes(root, value, k);
        if(v.size()==0){
            cout << "0" << endl;
            continue;
        }
        sort(v.begin(), v.end());
        for(auto x:v){
            cout << x << " ";
        }
        cout << endl;

    }

    return 0;
}