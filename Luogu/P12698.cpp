#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> es[250005];
int n, q, k, g[250005], vis[250005], s[250005], fa[250005], cnt[250005];
void dfs(int now)
{
    for (int nxt : es[now])
    {
        if (nxt == fa[now])
        {
            continue;
        }
        fa[nxt] = now, dfs(nxt);
    }
}
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v), es[v].push_back(u);
    }
    dfs(1);
    cin >> q;
    while (q--)
    {
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> s[i];
            vis[s[i]] = 1, g[s[i]] = s[i];
        }
        for (int i = 1; i <= k; i++)
        {
            int f = fa[s[i]];
            if (vis[f] == 1)
            {
                g[s[i]] = g[f];
            }
        }
        for (int i = 1; i <= k; i++)
        {
            cnt[dfn(s[i])]++;
        }
        long long ans = 0;
        for (int i = 1; i <= k; i++)
        {
            if (cnt[s[i]])
            {
                ans += cnt[s[i]] * (cnt[s[i]] - 1ll) / 2;
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= k; i++)
        {
            cnt[s[i]] = vis[s[i]] = 0;
        }
    }
    return 0;
}