#include<iostream>
using namespace std;

int merge(int a[], int beg, int end, int mid){

    int i = beg;
    int j = mid+1;
    int k = beg;
    int count = 0;
    int temp[100000];
    while(i<=mid && j<=end){
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
            count += mid-i + 1;
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

    return count;
}

int inversion_count(int a[], int beg, int end){

    if(beg>=end){
        return 0;
    }
    int mid = (beg+end)/2;
    int x = inversion_count(a, beg, mid);
    int y = inversion_count(a, mid+1, end);
    int z = merge(a, beg, end, mid);

    return x+y+z;
}

int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << inversion_count(a, 0, n-1) << endl;

    return 0;
}