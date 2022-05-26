#include <algorithm>
#include <iostream>
using namespace std;
int g[20005], dp[20005], sz[20005];
int dfn(int now)
{
    if (g[now] != now)
    {
        g[now] = dfn(g[now]);
    }
    return g[now];
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        int ga = dfn(a), gb = dfn(b);
        if (ga != gb)
        {
            g[gb] = ga;
            sz[ga] += sz[gb];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i] != i)
        {
            continue;
        }
        for (int j = n; j >= sz[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - sz[i]] + sz[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (abs(dp[i] - m) < abs(ans - m))
        {
            ans = dp[i];
        }
    }
    cout << ans << endl;
    return 0;
}