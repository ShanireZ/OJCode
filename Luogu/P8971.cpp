#include <cstring>
#include <iostream>
using namespace std;
#define MX 200005
#define MOD 1000000007
int status[MX], last[MX], pre[MX * 2], to[MX * 2], d[MX * 2], epos, n, l, r, cnt;
void addEdge(int u, int v, int w, int eid)
{
    to[eid] = v, d[eid] = w, pre[eid] = last[u];
    last[u] = eid;
}
int dfs(int now, int L, int R)
{
    status[now] = 0;
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i], w = d[i];
        if (status[nxt])
        {
            L = max(L, w - r), R = min(R, w - l);
        }
    }
    int ans = R - L + 1;
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i], w = d[i];
        if (status[nxt])
        {
            ans = min(ans, dfs(nxt, max(l, w - R), min(r, w - L)));
        }
    }
    return (ans < 0 ? 0 : ans);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> l >> r;
        epos = 0, cnt = n, memset(last, 0, sizeof(last));
        for (int i = 1; i < n; i++)
        {
            int op, u, v, w;
            cin >> op >> u >> v;
            if (op)
            {
                cin >> w;
                addEdge(u, v, w, ++epos);
                addEdge(v, u, w, ++epos);
                cnt -= (status[u] == 0) + (status[v] == 0);
                status[u] = status[v] = 1;
            }
        }
        long long ans = 1, base = r - l + 1;
        for (int i = 1; i <= cnt; i++) // 统计无限制点的贡献
        {
            ans = ans * base % MOD;
        }
        for (int i = 1; i <= n; i++) // 统计每棵树的限制点的贡献
        {
            if (status[i])
            {
                ans = ans * dfs(i, l, r) % MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}