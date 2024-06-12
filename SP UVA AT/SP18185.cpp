#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int a[500005], k[500005], g[500005], len[715];
int main()
{
    int n, m;
    cin >> n;
    int sz = sqrt(n), c = 0, gpos = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        k[i] = a[i];
        if (c == sz)
        {
            len[gpos] = c;
            c = 0, gpos++;
        }
        c++, g[i] = gpos;
    }
    len[gpos] = c;
    for (int i = 1; i <= gpos; i++)
    {
        int st = (i - 1) * sz + 1;
        sort(k + st, k + st + len[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y, v;
        cin >> opt >> x >> y;
        if (opt == 0)
        {
            cin >> v;
            int res = 0;
            while (x <= y)
            {
                if (x % sz == 1 && y - x + 1 >= len[g[x]])
                {
                    int p = lower_bound(k + x, k + x + len[g[x]], v) - k;
                    res += x + len[g[x]] - p;
                    x += len[g[x]];
                }
                else
                {
                    res += (a[x] >= v);
                    x++;
                }
            }
            cout << res << '\n';
        }
        else
        {
            int st = (g[x] - 1) * sz + 1;
            int p = lower_bound(k + st, k + st + len[g[x]], a[x]) - k;
            k[p] = a[x] = y;
            sort(k + st, k + st + len[g[x]]);
        }
    }
    return 0;
}