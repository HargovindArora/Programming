#include<iostream>
#include<cstring>
using namespace std;

int main(){

    int n;
    cin >> n;
    
    char a[1000];
    char largest[1000];
    cin.get();
    
    cin.getline(a, 1000);
    strcpy(largest,a);

    for(int i=0; i<n-1; i++){
        cin.getline(a, 1000);
        if(strlen(largest)<strlen(a)){
            strcpy(largest,a);
        }
    }
    cout << largest << endl;

    return 0;
}