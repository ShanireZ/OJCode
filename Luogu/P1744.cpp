#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int n, m, s, t, p[105][2];
double dis[105][105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i][0] >> p[i][1];
        fill(dis[i], dis[i] + 105, 1e15);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        double d = pow((p[x][0] - p[y][0]) * (p[x][0] - p[y][0]) + (p[x][1] - p[y][1]) * (p[x][1] - p[y][1]), 0.5);
        dis[x][y] = min(dis[x][y], d), dis[y][x] = min(dis[y][x], d);
    }
    cin >> s >> t;
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
    cout << fixed << setprecision(2) << dis[s][t] << endl;
    return 0;
}