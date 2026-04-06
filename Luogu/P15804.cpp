#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Qst
{
    int ed, id;
};
vector<Qst> qst[100005];
struct Path
{
    int to, w;
    bool operator<(const Path &other) const
    {
        return w > other.w;
    }
};
priority_queue<Path> pq;
int n, q, lst, dis[100005], ans[100005], r[100005];
void dijkstra(int p)
{
    fill(dis + 1, dis + 1 + n, 1e9);
    pq.push(Path{p, 0}), lst = p;
    while (pq.size())
    {
        int now = pq.top().to, w = pq.top().w;
        pq.pop();
        if (w < dis[now])
        {
            dis[now] = w;
            if (now > 1 && dis[now] + 1 < dis[now - 1])
            {
                pq.push(Path{now - 1, dis[now] + 1});
            }
            if (r[now] && dis[now] + 1 < dis[r[now]])
            {
                pq.push(Path{r[now], dis[now] + 1});
            }
        }
    }
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        qst[x].push_back(Qst{y, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (r[i])
        {
            dijkstra(i);
        }
        for (Qst qs : qst[i])
        {
            ans[qs.id] = (qs.ed > lst ? i - qs.ed : dis[qs.ed] + i - lst);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}