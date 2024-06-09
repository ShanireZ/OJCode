#include <algorithm>
#include <iostream>
using namespace std;
int vis[510005], g[510005], cnt[725];
long long a[510005], ans;
int main()
{
    int n, m, sz = 708;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vis[i] = 1, ans += a[i];
    }
    for (int i = 1; i <= sz; i++)
    {
        for (int j = (i - 1) * sz + 1; j <= i * sz; j++)
        {
            g[j] = i, cnt[i] += vis[j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        char opt;
        long long x, y;
        cin >> opt;
        if (opt == 'Q')
        {
            cout << ans << "\n";
        }
        else if (opt == 'D')
        {
            cin >> x;
            for (int j = 1; j <= sz && x; j++)
            {
                if (x > cnt[j])
                {
                    x -= cnt[j];
                }
                else
                {
                    for (int k = (j - 1) * sz + 1; k <= j * sz; k++)
                    {
                        x -= vis[k];
                        if (x == 0)
                        {
                            vis[k] = 0, ans -= a[k], cnt[j]--;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            cin >> x >> y;
            if (opt == 'I')
            {
                if (vis[x])
                {
                    ans += y - a[x];
                }
                else
                {
                    ans += y, cnt[g[x]]++, vis[x] = 1;
                }
                a[x] = y;
            }
            else
            {
                if (vis[x])
                {
                    ans -= y, a[x] -= y;
                }
            }
        }
    }
    return 0;
}
// TAG: 分块