#include<iostream>
#include<algorithm>
using namespace std;


bool safeDist(int a[], int n, int mid, int c){

    int cows = 1;
    int pos=a[0];

    for(int i=1; i<n; i++){

        if(a[i]-pos>=mid){
            pos = a[i];
            cows++;
            if (cows==c){
                return true;
            }
        }

    }

    return false;
}


int minDistCow(int a[], int n, int c){

    int s=0, e=a[n-1];
    int mid, ans=0;

    while(s<=e){

        mid = (s+e)/2;

        if(safeDist(a, n, mid, c)){
            ans= mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return ans;
}


int main(){

    int n, c;
    cin >> n >> c;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    cout << minDistCow(a, n, c) << endl;

    return 0;
}