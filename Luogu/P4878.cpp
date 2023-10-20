#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    long long v, w;
};
vector<Edge> es[1005];
long long n, c1, c2, cnt[1005], dis[1005], vis[1005];
bool spfa(int st)
{
    queue<int> q;
    memset(vis, 0, sizeof(vis)), memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0, q.push(st), vis[st] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop(), vis[now] = 0;
        for (Edge e : es[now])
        {
            long long nxt = e.v, w = e.w;
            if (dis[nxt] > dis[now] + w)
            {
                dis[nxt] = dis[now] + w;
                if (++cnt[nxt] > n && st == 0)
                {
                    return true;
                }
                if (vis[nxt] == 0)
                {
                    q.push(nxt), vis[nxt] = 1;
                }
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> c1 >> c2;
    for (int i = 1; i <= n; i++)
    {
        es[0].push_back(Edge{i, 0});
        es[i + 1].push_back(Edge{i, 0}); // 详见第一个题解
    }
    for (int i = 1; i <= c1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        es[a].push_back(Edge{b, c});
    }
    for (int i = 1; i <= c2; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        es[b].push_back(Edge{a, -c});
    }
    if (spfa(0))
    {
        cout << -1 << endl;
        return 0;
    }
    spfa(1);
    if (dis[n] == 0x3f3f3f3f3f3f3f3f)
    {
        cout << -2 << endl;
    }
    else
    {
        cout << dis[n] << endl;
    }
    return 0;
}