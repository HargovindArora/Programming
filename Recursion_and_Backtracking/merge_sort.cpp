#include<iostream>
using namespace std;


void merge(int *a, int beg, int end){

    int mid = (beg+end)/2;

    int i = beg;
    int j = mid+1;
    int k = beg;

    int temp[1000];

    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=end){
        temp[k++] = a[j++];
    }

    for(int i=beg; i<=end; i++){
        a[i] = temp[i];
    }

}


void merge_sort(int *a, int beg, int end){

    if(beg>=end){
        return;
    }
    int mid = (beg+end)/2;
    
    merge_sort(a, beg, mid);
    merge_sort(a, mid+1, end);
    merge(a, beg, end);
}


int main(){

    int a[1000];
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    merge_sort(a, 0, n-1);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}