#include<iostream>
using namespace std;

int binary_search(int a[], int n, int key){

    int mid, beg = 0, end = n-1;
    int i;
    while(beg<=end){
        mid = (beg+end)/2;

        if(a[i]==mid){
            return i;
        }
        else if(a[i]>mid){
            end = mid-1;
        }
        else{
            beg=mid+1;
        }
    }

    return -1;
}


int main(){

    int n;
    cin>> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[n];
    }
    int key;
    cin >> key;

    int x = binary_search(a, n, key);

    if(x!=-1){
        cout << "Element is present at index " << x << endl;
    }
    else{
        cout << "Element is not present" << endl;
    }

    return 0;
}