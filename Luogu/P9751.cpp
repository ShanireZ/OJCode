#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    long long v, a;
};
vector<Edge> to[10005];
queue<Edge> q;
long long dis[10005][105];
int main()
{
    int n, m, k, maxa = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, a;
        cin >> u >> v >> a;
        to[u].push_back(Edge{v, a});
        maxa = max(maxa, a);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1][0] = 0;
    q.push(Edge{1, 0});
    while (q.size())
    {
        long long now = q.front().v, t = q.front().a;
        q.pop();
        for (Edge e : to[now])
        {
            long long nxt = e.v, a = e.a;
            if (t >= a && dis[nxt][(t + 1) % k] > t + 1)
            {
                dis[nxt][(t + 1) % k] = t + 1;
                q.push(Edge{nxt, t + 1});
            }
            else if (t < a)
            {
                long long x = ceil(1.0 * (a - t) / k);
                if (t + x * k + 1 < dis[nxt][(t + x * k + 1) % k])
                {
                    dis[nxt][(t + x * k + 1) % k] = t + x * k + 1;
                    q.push(Edge{nxt, t + x * k + 1});
                }
            }
        }
    }
    if (dis[n][0] == 0x3f3f3f3f3f3f3f3f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dis[n][0] << endl;
    }
    return 0;
}