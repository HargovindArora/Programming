#include<iostream>
using namespace std;

int main(){

    int n, currSum=0, maxSum1=0, maxSum2=0, cumSum=0;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
        cumSum += arr[i];
        currSum += arr[i];
        if(currSum<0){
            currSum=0;
        }
        maxSum1 = max(currSum, maxSum1);
    }
    for(int i=0; i<n; i++){
        arr[i] = -arr[i];
    }
    currSum=0;
    for(int i=0; i<n; i++){
        currSum += arr[i];
        if(currSum<0){
            currSum = 0;
        }
        maxSum2 = max(maxSum2, currSum);
    }

    maxSum2 = cumSum - (-maxSum2);

    if(maxSum1 > maxSum2){
        cout << maxSum1 << endl;
    }
    else{
        cout << maxSum2 << endl;
    }

    return 0;
}