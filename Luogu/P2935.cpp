#include <algorithm>
#include <iostream>
using namespace std;
int p, f, c, dis[505][505], rec[505];
int main()
{
    cin >> p >> f >> c;
    for (int i = 1; i <= f; i++)
    {
        cin >> rec[i];
    }
    for (int i = 1; i <= p; i++)
    {
        fill(dis[i], dis[i] + 505, 0x3f3f3f3f);
        dis[i][i] = 0;
    }
    for (int i = 1; i <= c; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    for (int k = 1; k <= p; k++)
    {
        for (int i = 1; i <= p; i++)
        {
            for (int j = 1; j <= p; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int ans = 0x3f3f3f3f, pos = -1;
    for (int i = 1; i <= p; i++)
    {
        long long res = 0;
        for (int j = 1; j <= f; j++)
        {
            res += dis[i][rec[j]];
        }
        if (res < ans)
        {
            ans = res, pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}