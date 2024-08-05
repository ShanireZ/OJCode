#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <random>
using namespace std;
mt19937 gen(time(0));
int n, m, k, epos, pos, r[105], d[105], pre[105], lst[55], cb[55], choose[55];
int vis[55], dis[55];
queue<int> q;
void addEdge(int u, int v)
{
    r[++epos] = v;
    pre[epos] = lst[u];
    lst[u] = epos;
}
int bfs()
{
    for (int i = 1; i <= n; i++)
    {
        if (cb[i] == 1)
        {
            q.push(i), vis[i] = 1, dis[i] = 0;
        }
        else
        {
            dis[i] = 1e9;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int p = choose[i];
        q.push(p), vis[p] = 1, dis[p] = 0;
    }
    while (q.size())
    {
        int now = q.front();
        q.pop(), vis[now] = 0;
        for (int i = lst[now]; i; i = pre[i])
        {
            int nxt = r[i];
            if (dis[nxt] > dis[now] + d[i])
            {
                dis[nxt] = dis[now] + d[i];
                if (vis[nxt] == 0)
                {
                    q.push(nxt), vis[nxt] = 1;
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, dis[i]);
    }
    return res;
}
int SA()
{
    int res = 1e9;
    double T = 10000;
    while (T >= 1e-15)
    {
        int x = gen() % k + 1, y = gen() % (pos - k) + k + 1;
        swap(choose[x], choose[y]);
        int now = bfs();
        if (now < res || exp((res - now) / T) * 100 > gen() % 100)
        {
            res = now;
        }
        else
        {
            swap(choose[x], choose[y]);
        }
        T = 0.95 * T;
    }
    return res;
}
int main()
{
    cin >> n >> m >> k;
    if (n == m + k)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int r;
        cin >> r;
        addEdge(i, r + 1), addEdge(r + 1, i);
    }
    for (int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        d[i * 2 - 1] = d[i * 2] = w;
    }
    for (int i = 1; i <= m; i++)
    {
        int p;
        cin >> p;
        cb[p + 1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cb[i] == 0)
        {
            choose[++pos] = i;
        }
    }
    int ans = 1e9;
    while (double(clock()) / CLOCKS_PER_SEC <= 0.75)
    {
        shuffle(choose + 1, choose + 1 + pos, gen);
        ans = min(ans, SA());
    }
    cout << ans << endl;
    return 0;
}