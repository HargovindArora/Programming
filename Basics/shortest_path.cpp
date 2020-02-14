#include<iostream>

using namespace std;

int main(){

    char ch;
    ch = cin.get();

    int x=0, y=0;

    while(ch!='\n'){

        if(ch=='N' || ch =='n'){
            y++;
        }
        else if(ch=='S' || ch=='s'){
            y--;
        }
        else if(ch=='E' || ch=='e'){
            x++;
        }
        else{
            x--;
        }

        ch = cin.get();
    }

    if(x>0){
        while(x--){
            cout << 'E';
        }
    }
    else{
        x = abs(x);
        while(x--){
            cout << 'W';
        }
    }

    if(y>0){
        while(y--){
            cout << 'N';
        }
    }
    else{
        y = abs(y);
        while(y--){
            cout << 'S';
        }
    }

    return 0;
}