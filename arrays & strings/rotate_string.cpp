#include<iostream>
#include<cstring>
using namespace std;

void rotate(char *a, int k){

    int i=strlen(a);
    while(i>=0){
        a[i+k] = a[i];
        i--;
    }

    i=strlen(a);
    int j=i-k;
    int s=0;
    while(j<i){
        a[s]=a[j];
        j++;
        s++;
    }
    a[i-k] = '\0';

}

int main(){

    char a[100] = "Ram Ram";

    rotate(a, 5);
    cout << a;

    return 0;
}