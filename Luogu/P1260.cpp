#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int n, m, epos, last[1005], in[1005], dis[1005], times[1005], pre[10005], to[10005], d[10005];
queue<int> q;
void addEdge(int u, int v, int w, int eid)
{
    pre[eid] = last[u], to[eid] = v, d[eid] = w;
    last[u] = eid;
}
bool SPFA()
{
    memset(dis, 0x3f, sizeof(dis));
    in[n + 1] = 1, dis[n + 1] = 0, q.push(n + 1);
    while (q.size())
    {
        int now = q.front();
        in[now] = 0, q.pop();
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i], w = d[i];
            if (dis[nxt] > dis[now] + w)
            {
                dis[nxt] = dis[now] + w;
                if (in[nxt] == 0)
                {
                    times[nxt]++, in[nxt] = 1, q.push(nxt);
                    if (times[nxt] > n + 1)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(b, a, c, ++epos);
    }
    for (int i = 1; i <= n; i++)
    {
        addEdge(n + 1, i, 0, ++epos);
    }
    if (SPFA() == false)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int ex = 0;
    for (int i = 1; i <= n; i++)
    {
        ex = min(ex, dis[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] - ex << endl;
    }
    return 0;
}