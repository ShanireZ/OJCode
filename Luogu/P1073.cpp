#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 300005
// 1~n 走动 n+1~2n买 2n+1~3n卖
int n, m, epos, in[MX], dis[MX];
int pre[MX * 11], to[MX * 11], c[MX * 11], last[MX];
queue<int> q;
void addEdge(int u, int v, int w, int id)
{
    pre[id] = last[u], to[id] = v, c[id] = w;
    last[u] = id;
}
void SPFA()
{
    memset(dis, -0x3f, sizeof(dis));
    q.push(1), in[1] = 1, dis[1] = 0;
    while (q.size())
    {
        int now = q.front();
        q.pop(), in[now] = 0;
        for (int i = last[now]; i; i = pre[i])
        {
            int t = to[i], w = c[i];
            if (dis[t] < dis[now] + w)
            {
                dis[t] = dis[now] + w;
                if (in[t] == 0)
                {
                    q.push(t), in[t] = 1;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        addEdge(i, i + n, -x, ++epos);
        addEdge(i + n, i + n * 2, x, ++epos);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        addEdge(x, y, 0, ++epos);
        addEdge(x + n, y + n, 0, ++epos);
        addEdge(x + n * 2, y + n * 2, 0, ++epos);
        if (z == 2)
        {
            addEdge(y, x, 0, ++epos);
            addEdge(y + n, x + n, 0, ++epos);
            addEdge(y + n * 2, x + n * 2, 0, ++epos);
        }
    }
    SPFA();
    cout << dis[n * 3] << endl;
    return 0;
}