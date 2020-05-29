#include<iostream>
using namespace std;

int sumOfSubMatrix(int **arr, int n, int m){
    
    int sum=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tl=(i+1)*(j+1);
            int br=(n-i)*(m-j);
            sum += (tl*br)*arr[i][j];
        }
    }

    return sum;
}


int main(){

    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for(int i=0; i<n; i++){
        arr[i] = new int [m];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    cout << sumOfSubMatrix(arr, n, m) << endl;

    return 0;
}