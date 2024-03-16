#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, k, zs[100005][25], all[100005][25];
void dfs(int now, int fa)
{
    for (int nxt : to[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, now);
        for (int i = 1; i <= k; i++)
        {
            zs[now][i] += zs[nxt][i - 1];
        }
    }
}
void dfs2(int now, int fa)
{
    if (now != 1)
    {
        all[now][1] = zs[now][1] + all[fa][0];
        for (int i = 2; i <= k; i++)
        {
            all[now][i] = zs[now][i] + all[fa][i - 1] - zs[now][i - 2];
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
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> zs[i][0];
        all[i][0] = zs[i][0];
    }
    dfs(1, 0);
    for (int i = 1; i <= k; i++)
    {
        all[1][i] = zs[1][i];
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 0; j <= k; j++)
        {
            ans += all[i][j];
        }
        cout << ans << "\n";
    }
    return 0;
}