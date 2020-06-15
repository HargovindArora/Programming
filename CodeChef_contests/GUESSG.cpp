#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // solve();

    int n;
    cin >> n;
    ll beg = 1, end = n;
    char c1, c2;
    int i=1;
    bool flag=false;
   
    cout << 1;
    cin >> c1;
    if(c1=='L'){
        flag = true;
    }
    else{
        cout << 1;
        cin >> c1;
        if(c1=='L'){
            flag=false;
        }
        else{
            cout << n;
            cin >> c1;
            if(c1=='G'){
                flag=true;
            }
            else{
                cout << n;
                cin >> c1;
                if(c1=='G'){
                    flag=false;
                }
                else{
                    flag=true;
                }
            }
        }
    }
    i++;
    if(flag){
        while(beg<=end){

            if(flag && i%2==0){
                ll mid = (beg+end)/2;
                cout <<mid;
                cin >> c2;
                if(c2=='E'){
                    break;
                }
                else if(c2=='G'){
                    beg = mid+1;
                }
                else if(c2=='L'){
                    end = mid-1;
                }
            }
            else{
                ll mid = (beg+end)/2;
                cout <<mid;
                cin >> c2;
                if(c2=='E'){
                    break;
                }
            }
        }
        i++;
    }
    else{
        while(beg<=end){

            if(!flag && i%2!=0){
                ll mid = (beg+end)/2;
                cout <<mid;
                cin >> c2;
                if(c2=='E'){
                    break;
                }
                else if(c2=='G'){
                    beg = mid+1;
                }
                else if(c2=='L'){
                    end = mid-1;
                }
            }
            else{
                ll mid = (beg+end)/2;
                cout <<mid;
                cin >> c2;
                if(c2=='E'){
                    break;
                }
            }
        }
        i++;
    }

    return 0;

}