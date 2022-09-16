#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n, m, cnt, to[10005], pre[10005], last[5005], inq[5005], dis[5005], d[10005], t[5005];
void addEdge(int u, int v, int w, int eid)
{
    pre[eid] = last[u], to[eid] = v, d[eid] = w;
    last[u] = eid;
}
bool SPFA()
{
    inq[0] = 1, dis[0] = 0, q.push(0);
    while (q.size())
    {
        int now = q.front();
        q.pop(), inq[now] = 0;
        for (int i = last[now]; i != -1; i = pre[i])
        {
            int nxt = to[i], w = d[i];
            if (w + dis[now] < dis[nxt])
            {
                dis[nxt] = dis[now] + w;
                if (inq[nxt] == 0)
                {
                    if (++t[nxt] > n + 1) // SPFA判断负环要判断入队次数 此处多了个0号点所以是n+1个点
                    {
                        return false;
                    }
                    q.push(nxt), inq[nxt] = 1;
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    memset(last, -1, sizeof(last));
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(b, a, c, ++cnt);
    }
    for (int i = 1; i <= n; i++)
    {
        addEdge(0, i, 0, ++cnt);
    }
    memset(dis, 0x3f, sizeof(dis));
    if (SPFA() == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}