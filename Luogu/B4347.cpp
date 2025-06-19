#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct TZ
{
    int x1, y1, x2, y2, p, xt, yt;
    bool operator<(const TZ &oth) const
    {
        return p < oth.p;
    }
};
TZ t[105];
int n, m, c, k, res[505][505], p[505][505];
int main()
{
    cin >> n >> m >> c >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> t[i].x1 >> t[i].y1 >> t[i].x2 >> t[i].y2 >> t[i].p >> t[i].xt >> t[i].yt;
    }
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> p[i][j];
        }
    }
    sort(t + 1, t + k + 1), memset(res, -1, sizeof(res));
    for (int tid = 1; tid <= k; tid++)
    {
        for (int i = t[tid].x1, ex = 0; i <= t[tid].x2; i++, ex++)
        {
            for (int j = t[tid].y1, ey = 0; j <= t[tid].y2; j++, ey++)
            {
                res[i][j] = p[t[tid].xt + ex][t[tid].yt + ey];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}