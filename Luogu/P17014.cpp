#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int T, n, ans, vis[100005];
void dfs(int now, int from, int h)
{
    vis[now] = h;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        if (vis[nxt])
        {
            if ((h - vis[nxt]) % 2 == 0)
            {
                ans = 3;
            }
            continue;
        }
        dfs(nxt, now, h + 1);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ans = 2;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int u, v;
            cin >> u >> v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, 0, 1);
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
        {
            to[i].clear();
            vis[i] = 0;
        }
    }
    return 0;
}