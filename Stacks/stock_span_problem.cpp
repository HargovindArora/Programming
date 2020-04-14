#include<iostream>
#include<stack>
#define endl '\n'
using namespace std;

void printSpan(int arr[], int n){

    stack<int> s;
    int ans[n];
    for(int day=0; day<n; day++){

        int curPrice = arr[day];
        while(s.empty()==false && arr[s.top()] < curPrice){
            s.pop();
        }
        int betterDay = s.empty()? 0:s.top();
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
    int arr[100] = {100, 80, 60, 70, 60, 75, 85};

    printSpan(arr, n);

    return 0;
}