#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int element;
    cin >> element;

    int i;
    for(i=0;i<n;i++){
        if(element==a[i]){
            cout << "The element " << element << " is present at the index " << i << endl;
            break;
        }
    }

    if(i==n){
        cout << "The element " << element << " is not present" << endl;
    }

    return 0;
}