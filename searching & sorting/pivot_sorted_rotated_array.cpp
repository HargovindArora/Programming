#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a[1000];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int s=0, e=n-1;

    while(s<=e){

        int mid=(s+e)/2;
        
        if(mid<e && a[mid]>a[mid+1]){
            cout << mid << " ";
            break;
        }
        if(mid>s && a[mid]<a[mid-1]){
            cout << mid-1 << " ";
            break;
        }
        if(a[s]>=a[mid]){
            e = mid-1;
            continue;
        }
        if(a[mid]>=a[e]){
            s = mid+1;
        }
    }

    if(s>e){
        cout << "Pivot doesn't exist!";
    }
    cout << endl;

    return 0;
}