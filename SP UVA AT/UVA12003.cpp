#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int g[300005], len[555];
long long a[300005], k[300005];
int main()
{
    int n, m, u;
    cin >> n >> m >> u;
    int sz = sqrt(n), c = 0, gpos = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        k[i] = a[i];
        if (c == sz)
        {
            len[gpos] = c;
            gpos++, c = 0;
        }
        g[i] = gpos, c++;
    }
    len[gpos] = c;
    for (int i = 1; i <= gpos; i++)
    {
        int st = (i - 1) * sz + 1;
        sort(k + st, k + st + len[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, v, p;
        cin >> l >> r >> v >> p;
        long long res = 0, x = l, y = r;
        while (l <= r)
        {
            if (l % sz == 1 && r - l + 1 >= len[g[l]])
            {
                res += lower_bound(k + l, k + l + len[g[l]], v) - k - l;
                l += len[g[l]];
            }
            else
            {
                res += (a[l] < v);
                l++;
            }
        }
        int st = (g[p] - 1) * sz + 1;
        int pp = lower_bound(k + st, k + st + len[g[p]], a[p]) - k;
        k[pp] = a[p] = res * u / (y - x + 1);
        sort(k + st, k + st + len[g[p]]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << "\n";
    }
    return 0;
}