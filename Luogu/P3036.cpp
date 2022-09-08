#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, cnt, pos[100005][2], all[200010], dis[200010], done[200010];
struct Edge
{
    int v, w;
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> to[200010];
priority_queue<Edge> q;
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    q.push(Edge{pos[1][0], 0}), dis[pos[1][0]] = 0;
    while (q.size())
    {
        int now = q.top().v;
        q.pop();
        if (done[now])
        {
            continue;
        }
        done[now] = 1;
        for (int i = 0; i < int(to[now].size()); i++)
        {
            int nxt = to[now][i].v, w = to[now][i].w;
            if (dis[nxt] > dis[now] + w)
            {
                dis[nxt] = dis[now] + w, q.push(Edge{nxt, dis[nxt]});
            }
        }
    }
}
int main()
{
    cin >> n;
    int add = n + 2;
    for (int i = 1; i <= add; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
        all[++cnt] = pos[i][0], all[cnt + add] = pos[i][1];
    }
    sort(all + 1, all + 1 + cnt), sort(all + add + 1, all + add + 1 + cnt);
    int szx = unique(all + 1, all + 1 + cnt) - (all + 1);
    int szy = unique(all + add + 1, all + add + 1 + cnt) - (all + add + 1);
    for (int i = 1; i <= add; i++)
    {
        int x = pos[i][0] = lower_bound(all + 1, all + 1 + szx, pos[i][0]) - all;
        int y = pos[i][1] = lower_bound(all + add + 1, all + add + 1 + szy, pos[i][1]) - all;
        int w = (i <= 2) ? 0 : 1;
        to[x].push_back(Edge{y, w}), to[y].push_back(Edge{x, w});
    }
    dijkstra();
    int ans = (dis[pos[2][0]] == 0x3f3f3f3f) ? -1 : dis[pos[2][0]];
    cout << ans << endl;
    return 0;
}