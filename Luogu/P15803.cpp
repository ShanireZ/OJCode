#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
    long long v, w;
    bool operator<(Path oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> q;
struct Edge
{
    long long u, v, w, b;
};
Edge es[5005];
vector<int> t[5005];
long long dis[5005], n, m, ans = 1e18;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].w >> es[i].b;
        t[es[i].u].push_back(i);
        t[es[i].v].push_back(i);
    }
    for (int fe = 1; fe <= m; fe++)
    {
        long long len = es[fe].w;
        es[fe].w = 0;
        fill(dis + 1, dis + 1 + n, 1e18);
        q.push(Path{1, 0});
        while (q.size())
        {
            long long now = q.top().v, w = q.top().w;
            q.pop();
            if (dis[now] > w)
            {
                dis[now] = w;
                for (int eid : t[now])
                {
                    int nxt = es[eid].u + es[eid].v - now;
                    if (es[eid].b > es[fe].b)
                    {
                        continue;
                    }
                    if (dis[now] + es[eid].w < dis[nxt])
                    {
                        q.push(Path{nxt, dis[now] + es[eid].w});
                    }
                }
            }
        }
        ans = min(ans, dis[n]), es[fe].w = len;
    }
    cout << (ans == 1e18 ? -1 : ans) << endl;
    return 0;
}