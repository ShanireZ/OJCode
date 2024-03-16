#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[200005];
int n, zs[200005], ans[200005];
void dfs(int now, int fa)
{
    if (zs[now] == 0)
    {
        zs[now] = -1;
    }
    for (int nxt : to[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, now);
        zs[now] = max(zs[now], zs[now] + zs[nxt]);
    }
}
void dfs2(int now, int fa)
{
    if (now != 1)
    {
        if (zs[now] <= 0)
        {
            ans[now] = zs[now] + ans[fa] * (ans[fa] > 0);
        }
        else
        {
            ans[now] = max(zs[now], ans[fa]);
        }
    }
    for (int nxt : to[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs2(nxt, now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> zs[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    dfs(1, 0);
    ans[1] = zs[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}