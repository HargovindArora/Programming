#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {

        if (a[mid] == 1)
        {
            mid++;
            continue;
        }
        if (a[mid] == 2)
        {
            swap(a[mid], a[high]);
            high--;
            continue;
        }
        if (a[mid] == 0)
        {
            swap(a[low], a[mid]);
            mid++;
            low++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}