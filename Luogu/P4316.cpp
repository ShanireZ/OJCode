#include <iostream>
#include <queue>
using namespace std;
#define MX 100005
int n, m, ind[MX], otd[MX], last[MX], pre[MX * 2], to[MX * 2], w[MX * 2];
double p[MX], g[MX * 2], ans; // p[i] 到达点i的概率 g[i] 访问边i的概率
queue<int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> w[i];
        ind[v]++, otd[u]++;
        pre[i] = last[u], to[i] = v;
        last[u] = i;
    }
    p[1] = 1, q.push(1);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i];
            g[i] = p[now] / otd[now];
            p[nxt] += g[i];
            if (--ind[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        ans += w[i] * g[i];
    }
    printf("%.2lf\n", ans);
    return 0;
}