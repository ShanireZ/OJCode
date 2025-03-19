#include <algorithm>
#include <iostream>
using namespace std;
int m0[10005], prim[10005], vis[10005], n, ppos, mpos, cnt, ans = 1e9;
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prim[++ppos] = i;
        }
        for (int j = 1; j <= ppos && i * prim[j] <= n; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i * i)
        {
            m0[++mpos] = j;
        }
    }
    sort(m0 + 1, m0 + mpos + 1);
    mpos = unique(m0 + 1, m0 + mpos + 1) - m0 - 1;
    for (int i = 1; i <= mpos; i++)
    {
        for (int j = ppos; j >= 1; j--)
        {
            if (m0[i] + prim[j] == n)
            {
                cnt++;
                ans = min(ans, abs(m0[i] - prim[j]));
            }
        }
    }
    cout << cnt << endl
         << ans << endl;
    return 0;
}