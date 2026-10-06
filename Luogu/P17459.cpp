#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[2005], ans;
int n, m, rd[2005], cd[2005], vis[2005];
bool dfs(int now, int fb)
{
    if (now == n + 2)
    {
        return 1;
    }
    vis[now] = 1;
    for (int nxt : to[now])
    {
        if (vis[nxt] || nxt == fb)
        {
            continue;
        }
        if (dfs(nxt, fb))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        rd[v]++, cd[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (rd[i] == 0)
        {
            to[n + 1].push_back(i);
        }
        if (cd[i] == 0)
        {
            to[i].push_back(n + 2);
        }
    }
    for (int x = 1; x <= n; x++)
    {
        fill(vis + 1, vis + n + 3, 0);
        if (dfs(n + 1, x) == 0)
        {
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}