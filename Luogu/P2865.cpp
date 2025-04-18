#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> es[5005];
int n, r, dis[5005][2];
priority_queue<Edge> q;
int main()
{
    cin >> n >> r;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= r; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        es[a].emplace_back(Edge{b, d});
        es[b].emplace_back(Edge{a, d});
    }
    q.emplace(Edge{1, 0});
    while (q.size())
    {
        int now = q.top().v, w = q.top().w;
        q.pop();
        if (dis[now][1] != 0x3f3f3f3f)
        {
            continue;
        }
        else if (dis[now][0] == 0x3f3f3f3f)
        {
            dis[now][0] = w;
        }
        else if (w != dis[now][0])
        {
            dis[now][1] = w;
        }
        for (Edge e : es[now])
        {
            int nxt = e.v, d = e.w;
            if (dis[nxt][1] == 0x3f3f3f3f)
            {
                q.emplace(Edge{nxt, w + d});
            }
        }
    }
    cout << dis[n][1] << endl;
    return 0;
}