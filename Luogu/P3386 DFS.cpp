#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[505];
int l[505], r[505], vis[505]; // vis左侧点标记
bool dfs(int now, int t)
{
    if (vis[now] == t)
    {
        return false;
    }
    vis[now] = t;
    for (int nxt : to[now])
    {
        if (r[nxt] == 0 || dfs(r[nxt], t))
        {
            l[now] = nxt, r[nxt] = now;
            return true;
        }
    }
    return false;
}
int main()
{
    int n, m, e, ans = 0;
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (l[i] == 0)
        {
            ans += dfs(i, i);
        }
    }
    cout << ans << "\n";
    return 0;
}