#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[1005];
struct Path
{
    int v, w, t;
    bool operator<(const Path &oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> q;
int maxw[1005][1005];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        es[a].push_back(Edge{b, c}), es[b].push_back(Edge{a, c});
    }
    memset(maxw, 0x3f, sizeof(maxw));
    q.push(Path{1, 0, 0}), maxw[1][0] = 0;
    while (q.size())
    {
        int now = q.top().v, t = q.top().t;
        q.pop();
        for (Edge e : es[now])
        {
            int nxt = e.v, w = e.w;
            if (maxw[nxt][t] > max(maxw[now][t], w))
            {
                maxw[nxt][t] = max(maxw[now][t], w);
                q.push(Path{nxt, maxw[nxt][t], t});
            }
            if (t + 1 <= k && maxw[nxt][t + 1] > maxw[now][t])
            {
                maxw[nxt][t + 1] = maxw[now][t];
                q.push(Path{nxt, maxw[nxt][t + 1], t + 1});
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; i++)
    {
        ans = min(ans, maxw[n][i]);
    }
    cout << (ans != 0x3f3f3f3f ? ans : -1) << endl;
    return 0;
}