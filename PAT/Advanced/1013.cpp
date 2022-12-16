#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[1005];
int vis[1005];
void dfs(int now)
{
    vis[now] = 1;
    for (int i = 0; i < int(to[now].size()); i++)
    {
        int nxt = to[now][i];
        if (vis[nxt] == 0)
        {
            dfs(nxt);
        }
    }
}
int main() // 图的遍历+连通分量个数统计
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b), to[b].push_back(a);
    }
    for (int i = 1; i <= k; i++)
    {
        int x, cnt = 0;
        cin >> x;
        memset(vis, 0, sizeof(vis));
        vis[x] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == 0)
            {
                dfs(j), cnt++;
            }
        }
        cout << cnt - 1 << "\n";
    }
    return 0;
}