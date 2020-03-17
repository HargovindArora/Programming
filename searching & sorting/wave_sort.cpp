#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a[1000];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i+=2){

        if(i>0 && a[i-1]>a[i]){
            swap(a[i], a[i-1]);
        }
        if(i<=n-2 && a[i+1]>a[i]){
            swap(a[i], a[i-1]);
        }

    }

    for(int x=0; x<n; x++){
        cout << a[x] << " ";
    }
    cout << endl;

    return 0;
}