#include<iostream>
using namespace std;

int binary_search(int a[], int n, int key){

    int beg = 0, end = n-1;
    
    while(beg<=end){
        int mid = (beg+end)/2;

        if(key==a[mid]){
            return mid;
        }
        else if(a[mid]>key){
            end=mid-1;
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
        cin >> a[i];
    }
    int key;
    cin >> key;

    int x = binary_search(a, n, key);
    cout << x << endl;
    if(x!=-1){
        cout << "Element is present at index " << x << endl;
    }
    else{
        cout << "Element is not present" << endl;
    }

    return 0;
}