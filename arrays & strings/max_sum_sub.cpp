#include<iostream>
using namespace std;

int main(){

    int maxSum=0, curSum=0, left, right;
    int n;
    cin >> n;
    int arr[n], cumSum[n] = {0};
    
    cin >> arr[0];
    cumSum[0] = arr[0];

    for(int i=1; i<n; i++){
        cin >> arr[i];
        cumSum[i] = cumSum[i-1] + arr[i];
    }

    for(int i=1; i<n; i++){
        for(int j=i; j<n; j++){
            curSum = cumSum[j] - cumSum[i-1];

            if(curSum>maxSum){
                maxSum = curSum;
                left=i;
                right=j;
            }
        }
    }
    cout << maxSum << endl;
    for(int i=left; i<=right; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}