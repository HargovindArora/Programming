#include<iostream>
#include<stack>
#define endl '\n'
using namespace std;

void printSpan(int price[], int n){

    stack<int> s;
    int ans[n];
    s.push(0);
    ans[0] = 1;
    for(int day=1; day<=n-1; day++){

        int curPrice = price[day];
        while(s.empty()==false && price[s.top()] <= curPrice){
            s.pop();
        }
        int betterDay = s.empty()? -1:s.top();
        int span = day - betterDay;
        s.push(day);
        ans[day] = span;
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

int main(){

    int n = 7;
    int price[100] = {100, 80, 60, 70, 60, 75, 85};

    printSpan(price, n);

    return 0;
}