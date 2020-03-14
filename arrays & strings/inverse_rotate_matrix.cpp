#include<iostream>
#include<algorithm>
using namespace std;

void rotate_stl(int a[][1000], int m, int n){
    // Rotating matrix using STL rotate function and then doing transpose

    for(int i=0; i<m; i++){
        reverse(a[i], a[i]+m);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i<j){
                swap(a[i][j], a[j][i]);
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


}

int main(){

    int m, n;
    cin >> m >> n;
    int a[1000][1000];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    rotate_stl(a, m, n);

    return 0;
}