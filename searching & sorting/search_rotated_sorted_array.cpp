#include<iostream>
using namespace std;

int searchIn(int a[], int s, int e, int key){

    if(s>e){
        return -1;
    }

    int mid=(s+e)/2;

    if(a[mid]==key){
        return mid;
    }

    if(a[s]<=a[mid]){
        if(a[s]<=key && key<=a[mid]){
            return searchIn(a, s, mid-1, key);
        }
        else{
            return searchIn(a, mid+1, e, key);
        }
    }

    if(key>=a[mid] && key<=a[e]){
        return searchIn(a, mid+1, e, key);
    }

    return searchIn(a, s, mid-1, key);
}

int main(){

    int n;
    cin >> n;
    int a[1000];
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int key;
    cin >> key;

    cout << searchIn(a, 0, n-1, key);

    return 0;
}