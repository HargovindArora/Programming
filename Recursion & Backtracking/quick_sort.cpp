#include<iostream>
using namespace std;


int partition(int *a, int beg, int end){

    int i = beg-1;
    int j = beg;
    int pivot = a[end];

    for(; j<end; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[end]);
    return i+1;
}


void quicksort(int *a, int beg, int end){

    if(beg>=end){
        return;
    }

    int p = partition(a, beg, end);
    quicksort(a, beg, p-1);
    quicksort(a, p+1, end);
}


int main(){

    int a[] = {2, 1, 4, 6, 5, 7, 8};
    int n= sizeof(a)/sizeof(int);

    quicksort(a, 0, n-1);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}