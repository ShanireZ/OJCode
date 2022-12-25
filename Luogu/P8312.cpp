#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Path
{
    int tar, step;
};
queue<Path> pt;
int read(), vis[75][75][75], dis[75][75][75], d[75][75];
int main()
{
    int n = read(), m = read();
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), w = read();
        d[a][b] = min(d[a][b], w);
    }
    int k = read(), q = read();
    k = min(n - 1, k);
    memset(dis, 0x3f, sizeof(dis));
    for (int st = 1; st <= n; st++)
    {
        pt.push(Path{st, 0}), dis[st][st][0] = 0, vis[st][st][0] = 1;
        while (pt.size())
        {
            int now = pt.front().tar, step = pt.front().step;
            pt.pop(), vis[st][now][step] = 0;
            for (int nxt = 1; nxt <= n; nxt++)
            {
                int w = d[now][nxt];
                if (w != 0x3f3f3f3f && step < k && dis[st][nxt][step + 1] > dis[st][now][step] + w)
                {
                    dis[st][nxt][step + 1] = dis[st][now][step] + w;
                    if (vis[st][nxt][step + 1] == 0)
                    {
                        pt.push(Path{nxt, step + 1}), vis[st][nxt][step + 1] = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int a = read(), b = read(), ans = 0x3f3f3f3f;
        for (int j = 0; j <= k; j++)
        {
            ans = min(ans, dis[a][b][j]);
        }
        printf("%d\n", (ans == 0x3f3f3f3f ? -1 : ans));
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}