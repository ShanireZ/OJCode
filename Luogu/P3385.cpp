#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 6005
int last[MX], pre[MX], to[MX], times[MX], inq[MX], d[MX], dis[MX];
int n, m, epos;
void addEdge(int u, int v, int w, int eid)
{
    pre[eid] = last[u], to[eid] = v, d[eid] = w;
    last[u] = eid;
}
bool SPFA()
{
    queue<int> q;
    q.push(1), inq[1] = 1, dis[1] = 0;
    while (q.size())
    {
        int now = q.front();
        q.pop(), inq[now] = 0;
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i], w = d[i];
            if (w + dis[now] < dis[nxt])
            {
                dis[nxt] = dis[now] + w;
                if (inq[nxt] == 0)
                {
                    q.push(nxt), inq[nxt] = 1;
                    if (++times[nxt] > n)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(last, 0, sizeof(last));
        memset(times, 0, sizeof(times));
        memset(inq, 0, sizeof(inq));
        cin >> n >> m;
        epos = 0;
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w, ++epos);
            if (w >= 0)
            {
                addEdge(v, u, w, ++epos);
            }
        }
        if (SPFA())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}