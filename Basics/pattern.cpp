#include<iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

        for(int j=1; j<=n; j++){

            for(int space=1; space<=n-j; space++){
                cout << " ";
            }

            int val = j;

            for(int cnt=1; cnt<=j; cnt++){
                cout << val;
                val = val+1;
            }

            val = val-2;

            for(int cnt=1; cnt<=j-1; cnt++){
                cout << val;
                val = val-1;
            }

            cout << endl;

        }

        return 0;
}