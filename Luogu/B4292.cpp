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
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        dis[a][b] = dis[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << (dis[i][n] == 0x3f3f3f3f ? -1 : dis[i][n]) << " ";
    }
    return 0;
}