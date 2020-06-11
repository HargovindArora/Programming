#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

void solve()
{

    int p, t;
    cin >> p >> t;
    int arr[10000] = {0};

    for (int i = 0; i < t; i++)
    {
        int p1, p2, amount;
        cin >> p1 >> p2 >> amount;
        arr[p1] -= amount;
        arr[p2] += amount;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}