#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

void solve()
{

    int n;
    cin >> n;

    int beg = 1, end = n;
    char c1, c2;
    int i = 0;
    while (beg <= end)
    {

        int m = (beg + end) / 2;
        cout << m << endl;
        if (i % 2 == 0)
        {
            cin >> c1;
            if (c1 == 'E')
            {
                return;
            }
        }
        if (i % 2 != 0)
        {
            cin >> c2;
            if (c1 == c2)
            {
                if (c1 == 'E')
                {
                    return;
                }
                else if (c1 == 'G')
                {
                    beg = m + 1;
                }
                else
                {
                    end = m - 1;
                }
            }
            else
            {
                if (c1 == 'E')
                {
                    return;
                }
                else if (c1 == 'G')
                {
                    beg = m + 1;
                }
                else
                {
                    end = m - 1;
                }
            }
        }
        i++;
    }
    i = 0;
    beg = 1, end = n;
    while (beg <= end)
    {

        int m = (beg + end) / 2;
        cout << m << endl;
        if (i % 2 == 0)
        {
            cin >> c1;
            if (c1 == 'E')
            {
                return;
            }
        }
        if (i % 2 != 0)
        {
            cin >> c2;
            if (c1 == c2)
            {
                if (c1 == 'E')
                {
                    return;
                }
                else if (c1 == 'G')
                {
                    beg = m + 1;
                }
                else
                {
                    end = m - 1;
                }
            }
            else
            {
                if (c2 == 'E')
                {
                    return;
                }
                else if (c2 == 'G')
                {
                    beg = m + 1;
                }
                else
                {
                    end = m - 1;
                }
            }
        }
        i++;
    }

    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}