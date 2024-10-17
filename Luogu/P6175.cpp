#include <algorithm>
#include <iostream>
using namespace std;
int n, m, dis[105][105], rd[105][105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fill(dis[i], dis[i] + 105, 0x3f3f3f3f);
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w), dis[v][u] = min(dis[v][u], w);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            rd[i][j] = dis[i][j];
        }
    }
    long long res = 0x3f3f3f3f;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                // 此时i~j间距离不经过k,加入k后即可形成环
                // 注意使用i~k和k~j的直连最短路,因为此时的dis中距离已经更新ij作为中转点的情况
                res = min(res, 0ll + dis[i][j] + rd[i][k] + rd[k][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    if (res == 0x3f3f3f3f)
    {
        cout << "No solution." << endl;
    }
    else
    {
        cout << res << endl;
    }
    return 0;
}