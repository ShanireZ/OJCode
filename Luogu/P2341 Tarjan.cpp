#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans, pos, cnt, gid, g[10005], sz[10005], od[10005], dfn[10005], low[10005], s[10005];
int last[10005], to[50005], pre[50005];
void tarjan(int now)
{
    dfn[now] = low[now] = ++cnt;
    s[++pos] = now;
    for (int i = last[now]; i != 0; i = pre[i])
    {
        int t = to[i];
        if (dfn[t] == 0)
        {
            tarjan(t);
            low[now] = min(low[now], low[t]);
        }
        else if (g[t] == 0)
        {
            low[now] = min(low[now], dfn[t]);
        }
    }
    if (low[now] == dfn[now])
    {
        gid++;
        while (s[pos] != now)
        {
            g[s[pos]] = gid, sz[gid]++;
            pos--;
        }
        g[s[pos]] = gid, sz[gid]++;
        pos--;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        to[i] = b, pre[i] = last[a];
        last[a] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = last[i]; j != 0; j = pre[j])
        {
            int t = to[j];
            if (g[t] != g[i])
            {
                od[g[i]]++;
            }
        }
    }
    cnt = 0;
    for (int i = 1; i <= gid; i++)
    {
        if (od[i] == 0)
        {
            ans = i, cnt++;
        }
    }
    if (cnt == 1)
    {
        cout << sz[ans] << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}