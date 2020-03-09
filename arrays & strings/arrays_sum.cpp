#include<iostream>
using namespace std;

int calcSumLogic(int a[], int b[], int n, int m){

    int sum[n+1];
    int i=n-1, j=m-1, k=0;

    int result=0, carry=0;

    while(j>=0){
        result = a[i] + b[j] + carry;
        sum[k] = result%10;
        carry = result/10;
        i--;
        j--;
        k++; 
    }

    while(i>=0){
        result = a[i] + carry;
        sum[k] = (result%10);
        carry = result/10;
        k++;
        i--;
    }
    if(carry){
        sum[k] = 1;
        k++;
    }
    for(int x=k-1; x>=0; x--){
        cout << sum[x] << ", ";
    }
    cout << "END" << endl;

}


int calcSum(int a[], int b[], int n, int m){
    if(n>=m){
        return calcSumLogic(a, b, n, m);
    }
    else{
        return calcSumLogic(b, a, m, n);
    }
}


int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    int b[m];
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    calcSum(a, b, n, m);

    return 0;
}