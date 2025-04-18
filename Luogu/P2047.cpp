#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
long long dis[105][105], cnt[105][105], n, m;
int main()
{
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cnt[u][v] = cnt[v][u] = 1;
        dis[u][v] = dis[v][u] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] == dis[i][k] + dis[k][j])
                {
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
                }
                else if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    cnt[i][j] = cnt[i][k] * cnt[k][j];
                }
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        double ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && j != k && k != i)
                {
                    long long res = 0;
                    if (dis[i][j] == dis[i][k] + dis[k][j])
                    {
                        res += cnt[i][k] * cnt[k][j];
                    }
                    ans += 1.0 * res / cnt[i][j];
                }
            }
        }
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}