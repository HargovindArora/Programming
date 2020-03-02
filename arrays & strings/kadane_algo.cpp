#include<iostream>
using namespace std;

int main(){

    int currSum=0, maxSum=0, n;
    cin >>n ;

    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
        currSum = currSum + a[i];
        if(currSum<0){
            currSum = 0;
        }
        maxSum = max(currSum, maxSum);
    }

    cout << maxSum << endl;

    return 0;
}