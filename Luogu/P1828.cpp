#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dis[805][805], pos[505];
int main()
{
    int n, p, c, ans = 0x3f3f3f3f;
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i];
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= p; i++)
    {
        dis[i][i] = 0;
    }
    for (int i = 1; i <= c; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        dis[u][v] = dis[v][u] = min(dis[u][v], d);
    }
    for (int k = 1; k <= p; k++)
    {
        for (int i = 1; i <= p; i++)
        {
            for (int j = i + 1; j <= p; j++)
            {
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= p; i++)
    {
        int res = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[pos[j]][i] == 0x3f3f3f3f) // 有可能不是联通图
            {
                res = 0x3f3f3f3f;
                break;
            }
            res += dis[pos[j]][i];
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
// TAG: 最短路 Floyd Dijkstra 枚举