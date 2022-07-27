#include <cstring>
#include <iostream>
using namespace std;
int n, m, pos, g[10005], sz[10005], od[10005], s[10005], vis[100005];
int to[50005], pre[50005], last[10005];       // 正图链式前向星
int tors[50005], prers[50005], lastrs[10005]; // 反图链式前向星
void dfs(int now)
{
    vis[now] = 1;
    for (int i = last[now]; i != 0; i = pre[i])
    {
        int t = to[i];
        if (vis[t])
        {
            continue;
        }
        dfs(t);
    }
    s[++pos] = now;
}
void dfsrs(int now, int gid)
{
    vis[now] = 1, g[now] = gid, sz[gid]++;
    for (int i = lastrs[now]; i != 0; i = prers[i])
    {
        int t = tors[i];
        if (vis[t])
        {
            continue;
        }
        dfsrs(t, gid);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        to[i] = b, tors[i] = a;
        pre[i] = last[a], prers[i] = lastrs[b];
        last[a] = lastrs[b] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    pos = 0;
    for (int i = n; i >= 1; i--)
    {
        int now = s[i];
        if (vis[now] == 0)
        {
            dfsrs(now, ++pos);
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
    int ans, cnt = 0; // 出度为0的强连通可以当明星 如果有多个强连通满足那么无解
    for (int i = 1; i <= pos; i++)
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