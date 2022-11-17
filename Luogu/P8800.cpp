#include <algorithm>
#include <iostream>
using namespace std;
long long cnt[200005], lim[200005];
int main()
{
    long long n, m, l = 1e9, r = 1e9;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cnt[i];
        l = min(l, cnt[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> lim[i];
        r = min(r, lim[i] + cnt[i]);
    }
    while (l <= r)
    {
        long long mid = (l + r) / 2, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            tot += max(0ll, mid - cnt[i]);
        }
        (tot > m) ? r = mid - 1 : l = mid + 1;
    }
    cout << r << endl;
    return 0;
}