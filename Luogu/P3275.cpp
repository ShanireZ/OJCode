#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 100005
queue<int> q;
int n, m, epos;
int last[MX], times[MX], dis[MX], in[MX], pre[MX * 3], to[MX * 3], d[MX * 3];
void addEdge(int u, int v, int w, int eid)
{
    pre[eid] = last[u], to[eid] = v, d[eid] = w;
    last[u] = eid;
}
bool SPFA()
{
    memset(dis, -1, sizeof(dis));
    in[n + 1] = 1, dis[n + 1] = 0, q.push(n + 1);
    while (q.size())
    {
        int now = q.front();
        in[now] = 0, q.pop();
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i], w = d[i];
            if (dis[nxt] < dis[now] + w)
            {
                dis[nxt] = dis[now] + w;
                if (in[nxt] == 0)
                {
                    in[nxt] = 1, times[nxt]++, q.push(nxt);
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
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int opt, a, b;
        cin >> opt >> a >> b;
        if (opt == 1)
        {
            addEdge(a, b, 0, ++epos);
            addEdge(b, a, 0, ++epos);
        }
        else if (opt == 2)
        {
            addEdge(a, b, 1, ++epos);
        }
        else if (opt == 3)
        {
            addEdge(b, a, 0, ++epos);
        }
        else if (opt == 4)
        {
            addEdge(b, a, 1, ++epos);
        }
        else
        {
            addEdge(a, b, 0, ++epos);
        }
        if (a == b && opt % 2 == 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        addEdge(n + 1, i, 1, ++epos); // 要求每人糖果必须为正整数
    }
    if (SPFA() == false)
    {
        cout << -1 << endl;
        return 0;
    }
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += dis[i];
    }
    cout << tot << endl;
    return 0;
}