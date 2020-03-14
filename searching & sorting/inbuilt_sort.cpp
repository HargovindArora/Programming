#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b){
    cout << "Comparing " << a << "and " << b << endl;
    return a>b;
}

int main(){

    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    for(int i=0; i<n; i++){
        cout << a[i] << ", ";
    }

    cout << endl;

    return 0;
}