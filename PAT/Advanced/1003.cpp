#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 505
struct Path
{
    int t, d;
    bool operator<(const Path oth) const
    {
        return d > oth.d;
    }
};
priority_queue<Path> q;
int read(), g[MX][MX], dis[MX], res[MX], ok[MX], cnt[MX], tot[MX];
int main() // 最短路径计数+最大[最短路径点权值和]
{
    memset(dis, 0x3f, sizeof(dis)), memset(g, 0x3f, sizeof(g));
    int n = read(), m = read(), st = read() + 1, ed = read() + 1;
    for (int i = 1; i <= n; i++)
    {
        res[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        int a = read() + 1, b = read() + 1, l = read();
        g[a][b] = g[b][a] = min(g[b][a], l);
    }
    cnt[st] = 1, dis[st] = 0, tot[st] = res[st], q.push(Path{st, 0});
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
                    tot[nxt] = res[nxt] + tot[now], cnt[nxt] = cnt[now];
                    q.push(Path{nxt, dis[nxt]});
                }
                else if (dnow + d == dis[nxt])
                {
                    tot[nxt] = max(tot[nxt], tot[now] + res[nxt]);
                    cnt[nxt] += cnt[now];
                }
            }
        }
    }
    printf("%d %d", cnt[ed], tot[ed]);
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