#include <cstring>
#include <iostream>
using namespace std;
int n, w[105][105][2], pre[105], back[105], va[105], vb[105], vis[105], slc[105];
void bfs(int st, int turn, int mode)
{
    memset(pre, 0, sizeof(pre)), memset(slc, 0x3f, sizeof(slc));
    int x, y = 0, pos = 0;
    back[y] = st;
    while (back[y])
    {
        int mins = 0x3f3f3f3f;
        x = back[y], vis[y] = turn;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == turn)
            {
                continue;
            }
            if (va[x] + vb[i] - w[x][i][mode] < slc[i])
            {
                slc[i] = va[x] + vb[i] - w[x][i][mode], pre[i] = y;
            }
            if (slc[i] < mins)
            {
                mins = slc[i], pos = i;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (vis[i] == turn)
            {
                va[back[i]] -= mins, vb[i] += mins;
            }
            else
            {
                slc[i] -= mins;
            }
        }
        y = pos;
    }
    while (y)
    {
        back[y] = back[pre[y]];
        y = pre[y];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j][1];
            w[i][j][0] = -w[i][j][1]; // 求最小只需要将边权变负即可
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bfs(i, i, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        ans -= va[i] + vb[i];
    }
    cout << ans << endl;
    memset(back, 0, sizeof(back)), memset(vis, 0, sizeof(vis));
    memset(va, 0, sizeof(va)), memset(vb, 0, sizeof(vb));
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bfs(i, i, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        ans += va[i] + vb[i];
    }
    cout << ans << endl;
    return 0;
}