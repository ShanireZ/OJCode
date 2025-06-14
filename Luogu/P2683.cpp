#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, dis[105][105];
int main()
{
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
    }
    while (m--)
    {
        int op, u, v, w;
        cin >> op >> u >> v;
        if (op == 0)
        {
            cout << (dis[u][v] == 0x3f3f3f3f ? -1 : dis[u][v]) << endl;
        }
        else
        {
            cin >> w;
            if (dis[u][v] > w)
            {
                dis[u][v] = dis[v][u] = w;
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        dis[i][j] = min({dis[i][j], dis[i][u] + w + dis[v][j], dis[i][v] + w + dis[u][j]});
                    }
                }
            }
        }
    }
    return 0;
}