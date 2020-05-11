#include<bits/stdc++.h>
using namespace std;

class node {
public :
    node *left;     //Left child node denotes 0 bit
    node *right;    //Right child node denotes 1 bit
    vector <int> v; //Vector to contain all the indices of which this bit is a part of at ith place
    node(){
        left = right = NULL ;
    }
};

class Trie {
private :
    node *root ;
public :
    Trie(){
        root = new node() ;
    }
    void insert(int n,int index){
        node *temp = root;
        for(int i=31 ; i>=0 ; i--){
            int bit = (n >> i) & 1; //Get ith bit
            if(bit == 0){
                //0 means node must have a left child to indicate it
                if(temp->left == NULL){
                    temp->left = new node();
                }
                //Insert the index of the number into the vector
                temp->v.push_back(index);
                temp = temp->left ;
            }
            else {
                //1 means node must have a right node to indicate it  
                if(temp->right == NULL){
                    temp->right = new node() ;
                }
                //Insert the index of the number into the vector
                temp->v.push_back(index);
                temp = temp->right ;
            }
        }
        temp->v.push_back(index);
    }

    int maxXor(int value,int left,int right){
        //Maximise xor with value between index range <left,right>
        int currentXor = 0 ;
        node *temp = root;
        for(int j=31;j>=0;j--){
            //Proceed bit by bit
            int bit = (value >> j)&1;
            //To maximise xor , we need as many opposite bits as possible
            //Move right i.e. towards 1 bit side if value has a 0 bit at jth position
            if(bit == 0){
                //Value has a 0 bit at jth pos 
                //Get a number with 1 bit , move right if there is a right child node between the <left,right> range
                if(temp->right != NULL && binarySearchRange(temp->right->v,left,right)){
                    temp = temp->right ;
                    currentXor += (1<<j) ;  //Add the number with jth bit set to the currentXor
                }
                else {
                    //Else move left
                    temp = temp->left ;
                }
            }
            else {
                //Value has 1 bit at jth pos , move left if possible
                if(temp->left != NULL && binarySearchRange(temp->left->v,left,right)) {
                    temp = temp->left ;
                }
                else {
                    temp = temp->right ;
                    currentXor += (1<<j);   //Add the number with jth bit set to the currentXor
                }
            }
        }
        return currentXor ;
    }

    bool binarySearchRange(vector<int> v,int l,int r){
        //Vector v has indices stored of the numbers of which this bit is a part of 
        //Since the insertion took place in increasing order , vector is already sorted
        int s = 0;
        int e = v.size() - 1;
        while(s <= e){
            int mid = (s+e)/2 ;
            int val = v[mid];
            if(val >= l && val <= r){
                return true ;
            }
            else if(val < l){
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return false ;
    }
};
int main() {
    int q ;
    cin >> q;
    Trie t;
    int index = 0;
    while(q--){
        int type ;
        cin >> type ;
        if(type == 0){
            //New entry
            int x ;
            cin >> x ;
            t.insert(x,index++);
        }
        else {
            //Query point
            int l,r,x ;
            cin >> l >> r >> x;
            cout << t.maxXor(x,l-1,r-1) << endl;
        }
    }
    return 0;
}