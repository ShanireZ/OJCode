#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int ms[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n, q, cnt, res[200005], vis[1005][1005], tp[1005][1005];
pair<int, int> opt[200005];
void sign(int x, int y)
{
    vis[x][y] = 1, cnt--;
    for (int i = 0; i < 4; i++) // 检查当前点的四周是否能到当前点
    {
        int nx = x + ms[i][0], ny = y + ms[i][1], t = tp[nx][ny];
        if (vis[nx][ny] == 0 && (t == -1 || (t + i == 1 || t + i == 5))) // 互为反方向
        {
            sign(nx, ny);
        }
    }
}
void check(int x, int y, int t)
{
    if (vis[x][y] == 0)
    {
        for (int i = 0; i < 4; i++) // 检查当前点的四周是否有标记点
        {
            if (t == -1 || t == i) // 可行进方向
            {
                int nx = x + ms[i][0], ny = y + ms[i][1];
                if (vis[nx][ny])
                {
                    sign(x, y);
                    break;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> q;
    memset(tp, -1, sizeof(tp)), cnt = n * n;
    for (int i = 0; i <= n + 1; i++)
    {
        vis[0][i] = vis[n + 1][i] = vis[i][0] = vis[i][n + 1] = 1;
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        char t;
        cin >> x >> y >> t;
        opt[i] = {x, y}, tp[x][y] = string("LRUD").find(t);
    }
    for (int i = 1; i <= n; i++) // 检查 每行第1和第n列,每列第1和第n行 是否能出局
    {
        check(i, 1, tp[i][1]), check(i, n, tp[i][n]);
        check(1, i, tp[1][i]), check(n, i, tp[n][i]);
    }
    for (int i = q; i >= 1; i--)
    {
        res[i] = cnt;
        int x = opt[i].first, y = opt[i].second;
        tp[x][y] = -1, check(x, y, -1);
    }
    for (int i = 1; i <= q; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}