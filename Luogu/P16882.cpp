#include <algorithm>
#include <iostream>
using namespace std;
#define MX 12005
long long T, n, m, k, a[MX], b[MX], ra[MX], rb[MX];
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
            b[i] += b[i - 1];
        }
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            if (i > n)
            {
                ra[i] = ra[i - 1];
                continue;
            }
            ra[i] = 0;
            for (int l = 0; l <= i; l++)
            {
                ra[i] = max(ra[i], a[l] + a[n] - a[n + l - i]);
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (i > m)
            {
                rb[i] = rb[i - 1];
                continue;
            }
            rb[i] = 0;
            for (int l = 0; l <= i; l++)
            {
                rb[i] = max(rb[i], b[l] + b[m] - b[m + l - i]);
            }
        }
        long long ans = 0;
        for (int i = 0; i <= k; i++)
        {
            ans = max(ans, ra[i] + rb[k - i]);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}