#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int maxSum=0, currSum=0, left=-1, right=-1;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            currSum=0;
            for(int k=i;k<=j;k++){
                currSum += a[k];
            }
            if(currSum>maxSum){
                maxSum = currSum;
                left = i;
                right = j;
            }
        }
    }

    cout << "The maximum sum is " << maxSum << endl;
    for(int i=left; i<=right; i++){
        cout << a[i] << ",";
    }
    cout << endl;

    return 0;
}