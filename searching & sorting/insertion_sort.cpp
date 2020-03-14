#include<iostream>
using namespace std;

void insertion_sort(int a[], int n){

    for(int i=1; i<=n-1; i++){
        int e=a[i];
        int j=i-1;
        while(j>=0 and e<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=e;
    }

}


int main(){

    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    insertion_sort(a, n);

    for(int i=0; i<n; i++){
        cout << a[i] << ", ";
    }

    cout << endl;

    return 0;
}