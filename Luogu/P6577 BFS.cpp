#include <cstring>
#include <iostream>
using namespace std;
int n, m, vis[505], back[505], pre[505];
long long ans, w[505][505], va[505], vb[505], slc[505];
void bfs(int st, int turn)
{
    memset(pre, 0, sizeof(pre));
    memset(slc, 0x3f, sizeof(slc));
    int x, y = 0, pos = 0;
    back[y] = st;
    while (back[y])
    {
        long long mins = 0x3f3f3f3f3f3f3f3f;
        x = back[y], vis[y] = turn;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == turn)
            {
                continue;
            }
            if (va[x] + vb[i] - w[x][i] < slc[i])
            {
                slc[i] = va[x] + vb[i] - w[x][i], pre[i] = y;
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
    memset(w, -0x3f, sizeof(w));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int y, c;
        long long h;
        cin >> y >> c >> h;
        w[y][c] = max(w[y][c], h);
        va[y] = max(va[y], h);
    }
    for (int i = 1; i <= n; i++)
    {
        bfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        ans += va[i] + vb[i];
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << back[i] << endl;
    }
    return 0;
}