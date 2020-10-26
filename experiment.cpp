#include <iostream>
using namespace std;
int main() {
    
    int num, mat[5][5];
    int n=5;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            mat[i][j] = x;
        }
    }
    int rank;
    cin >> num;
    if(num < mat[0][0]){
        cout << n*n+1 << endl;
        return 0;
    }
    if(num == mat[0][0]){
        cout << n*n << endl;
        return 0;
    }
    if(num >= mat[n-1][n-1]){
        cout << 1 << endl;
        return 0;
    }

    int i=0, j=n-1, count=0;
    while(i<n and j>=0){

        if(mat[i][j]>num){
            j--;
            continue;
        }
        if(mat[i][j]<=num){
            count += (n-j-1);
            i++;
        }
    }

    if(i!=n){
        int ext = (n-i)*n;
        count += ext;
    }

    cout << count+1 << endl;

    return 0;
}
