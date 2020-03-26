#include<iostream>
using namespace std;


int binarySearch(int *a, int beg, int end, int key){

    if(beg>end){
        return -1;
    }
    int mid = (beg+end)/2;
    if(a[mid]==key){
        return mid;
    }
    if(a[mid]>key){
        return binarySearch(a, beg, mid-1, key);
    }
    if(a[mid]<key){
        return binarySearch(a, mid+1, end, key);
    }
}


int main(){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int key;
    cin >> key;

    cout << binarySearch(a, 0, n-1, key);

    return 0;
}