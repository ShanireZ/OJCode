#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int times[205];
int dis[205][205];
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = 0x3f3f3f3f;
        }
        dis[i][i] = 0;
        cin >> times[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    int q, k = 0;
    cin >> q;
    for (int o = 1; o <= q; o++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        if (times[x] > t || times[y] > t)
        {
            cout << -1 << endl;
            continue;
        }
        while (k < n && times[k] <= t) //! floyd算法 k随着恢复而增加
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
            k++;
        }
        if (dis[x][y] == 0x3f3f3f3f)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[x][y] << endl;
        }
    }
    return 0;
}