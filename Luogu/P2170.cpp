#include <algorithm>
#include <iostream>
using namespace std;
int n, m, k, ans, fa[20005], dp[20005], cnt[20005];
int dfs(int now)
{
    if (fa[now] == now)
    {
        return now;
    }
    fa[now] = dfs(fa[now]);
    return fa[now];
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i, cnt[i] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        a = dfs(a), b = dfs(b);
        if (a != b)
        {
            fa[a] = b, cnt[b] += cnt[a], cnt[a] = 0;
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= cnt[i]; j--)
        {
            if (dp[j - cnt[i]] == 1)
            {
                dp[j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1 && abs(m - i) < abs(m - ans))
        {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}