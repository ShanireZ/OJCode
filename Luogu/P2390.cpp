#include <algorithm>
#include <iostream>
using namespace std;
int x[50005];
int main()
{
    int t, n;
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2, cost = 2e9;
        for (int st = 1; st + mid - 1 <= n; st++)
        {
            int ed = st + mid - 1;
            if ((x[st] < 0 && x[ed] < 0) || (x[st] >= 0 && x[ed] >= 0))
            {
                cost = min(cost, max(abs(x[st]), abs(x[ed])));
            }
            else
            {
                cost = min(cost, abs(x[st]) + abs(x[ed]) + min(abs(x[st]), abs(x[ed])));
            }
        }
        cost <= t ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}