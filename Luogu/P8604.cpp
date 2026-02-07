#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, u, v, cnt, ans, vis[1005];
vector<int> es[1005];
void dfs(int now, int del)
{
    vis[now] = 1;
    if (now == v)
    {
        return;
    }
    for (int nxt : es[now])
    {
        if (vis[nxt] == 1 || nxt == del)
        {
            continue;
        }
        dfs(nxt, del);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        es[u].push_back(v), es[v].push_back(u);
    }
    cin >> u >> v;
    dfs(u, 0);
    if (vis[v] == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != u && i != v)
        {
            fill(vis, vis + n + 1, 0);
            dfs(u, i);
            ans += (vis[v] == 0);
        }
    }
    cout << ans << endl;
    return 0;
}