#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int k;
    cin >> k;
    char board[8][8];

    memset(board, '.', sizeof(board));

    
    
    if(k==64){
        board[0][0] = 'O';
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cout << board[i][j];
            }
            cout << endl;
        }
        return;
    }

    if(k==1){
        board[0][0] = 'O';
        board[0][1] = 'X';
        board[1][0] = 'X';
        board[1][1] = 'X';
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cout << board[i][j];
            }
            cout << endl;
        }
        return;
    }

    int x = 64-k, y=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(y==x){
                board[7][7] = 'O';
                for(int i=0; i<8; i++){
                    for(int j=0; j<8; j++){
                        cout << board[i][j];
                    }
                    cout << endl;
                }
                return;
            }
            else{
                board[i][j] = 'X';
                y++;
            }
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        
        solve();
        
    }

    return 0;
}