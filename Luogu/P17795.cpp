#include <algorithm>
#include <iostream>
using namespace std;
long long n, k, a[200005], b[200005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    long long l = 1, r = 1e18;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long now = mid, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > mid)
            {
                cnt = 1e18;
                break;
            }
            if (a[i] > now)
            {
                cnt++, now = mid - a[i];
            }
            else
            {
                now = min(now - a[i] + b[i] * (cnt == 0), mid);
            }
        }
        if (cnt <= k)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}