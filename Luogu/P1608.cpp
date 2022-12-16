#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 2005
struct Path
{
    int t, d;
    bool operator<(const Path oth) const
    {
        return d > oth.d;
    }
};
priority_queue<Path> q;
int read(), cnt[MX], dis[MX], ok[MX], g[MX][MX];
int main()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(g, 0x3f, sizeof(g));
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), d = read();
        g[u][v] = min(d, g[u][v]);
    }
    cnt[1] = 1, dis[1] = 0, q.push({1, 0});
    while (q.size())
    {
        int now = q.top().t, dnow = q.top().d;
        q.pop();
        if (ok[now])
        {
            continue;
        }
        ok[now] = 1;
        for (int nxt = 1; nxt <= n; nxt++)
        {
            int d = g[now][nxt];
            if (d != 0x3f3f3f3f)
            {
                if (dnow + d < dis[nxt])
                {
                    dis[nxt] = dnow + d;
                    cnt[nxt] = cnt[now], q.push(Path{nxt, dis[nxt]});
                }
                else if (dnow + d == dis[nxt])
                {
                    cnt[nxt] += cnt[now];
                }
            }
        }
    }
    if (cnt[n] == 0)
    {
        printf("No answer\n");
    }
    else
    {
        printf("%d %d\n", dis[n], cnt[n]);
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