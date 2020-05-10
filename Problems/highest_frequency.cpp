// #include<bits/stdc++.h>
// #define ll long long int
// #define endl '\n'
// using namespace std;

// int main(){

//     int n;
//     cin >> n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }
//     unordered_map<int, int> m;
//     for(int i=0; i<n; i++){
//         m[a[i]]++;
//     }
//     int count = INT_MIN;
//     for(int i=0; i<n; i++){
//         count = max(count, m[a[i]]);
//     }
//     for(int i=0; i<n; i++){
//         if(m[a[i]]==count){
//             cout << a[i] << endl;
//             break;
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, int> m; //Key,Freq pair
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    int maxFreq = 0;
    int ans = 0;
    for (auto it : m)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            ans = it.first;
        }
    }
    cout << ans ;

    return 0;
}