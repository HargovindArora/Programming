#include<iostream>
using namespace std;

float squareRootBs(int no, int p){

    int s=0, e=no;
    float ans;
    int mid;

    while(s<=e){
        mid = (s+e)/2;

        if(mid*mid==no){
            ans = mid;
            break;
        }
        if(mid*mid<no){
            ans = mid;
            s = mid+1;
            continue;
        }
        else{
            e = mid-1;
        }
    }

    float inc = 0.1;

    for(int i=0; i<p; i++){

        while(ans*ans<=no){
            ans += inc;
        }

        ans -= inc;
        inc = inc/10;

    }

    return ans;
}

int main(){

    cout << squareRootBs(10, 4) << endl;

    return 0;
}