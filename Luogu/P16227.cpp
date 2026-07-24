#include <algorithm>
#include <iostream>
using namespace std;
int n, k, l = 1, r = 1e9, a[1000005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (l <= r)
    {
        long long t = 0, m = (l + r) / 2;
        for (int i = 1; i <= n; i++)
        {
            t += (a[i] - 1) / m;
        }
        t <= k ? r = m - 1 : l = m + 1;
    }
    cout << l << endl;
    return 0;
}