#include<iostream>
using namespace std;


int fastpower(int a, int b){

    if(b==0){
        return 1;
    }
    int smallAns = fastpower(a, b/2);
    smallAns *= smallAns;

    if(b&1){
        return a*smallAns;
    }
    else{
        return smallAns;
    }

}


int main(){

    int a, b;
    cin >> a >> b;

    cout << fastpower(a, b) << endl;

    return 0;
}