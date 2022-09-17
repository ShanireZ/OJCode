#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int n, m, epos, last[5005], times[5005], in[5005], dis[5005], pre[10005], to[10005], d[10005];
queue<int> q;
void addEdge(int u, int v, int w, int eid)
{
    pre[eid] = last[u], to[eid] = v, d[eid] = w;
    last[u] = eid;
}
bool SPFA()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[n + 1] = 0, in[n + 1] = 1, q.push(n + 1);
    while (q.size())
    {
        int now = q.front();
        in[now] = 0, q.pop();
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i], w = d[i];
            if (dis[now] + w < dis[nxt])
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
    for (int i = 1; i <= n; i++)
    {
        addEdge(n + 1, i, 0, ++epos);
    }
    for (int i = 1; i <= m; i++)
    {
        int opt, a, b, c;
        cin >> opt >> a >> b;
        if (opt == 1)
        {
            cin >> c;
            addEdge(a, b, -c, ++epos);
        }
        else if (opt == 2)
        {
            cin >> c;
            addEdge(b, a, c, ++epos);
        }
        else
        {
            addEdge(b, a, 0, ++epos);
        }
    }
    if (SPFA())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}