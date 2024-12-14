#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int n, k;
    cin >> n >> k;
    int mx = -1e9, mn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]), mn = min(mn, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < k)
        {
            a[i] = mn;
        }
        else if (a[i] > k)
        {
            a[i] = mx;
        }
        cout << a[i] << " ";
    }
    return 0;
}