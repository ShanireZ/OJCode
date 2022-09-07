#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, t;
    long long w;
};
Edge es[300005];
vector<int> way[300005];
long long dis[300005];
int n, s, t, first, times[300005];
void dfs(int now, int from)
{
    times[now]++;
    for (int i = 0; i < int(way[now].size()); i++)
    {
        int eid = way[now][i];
        if (from == eid)
        {
            continue;
        }
        int nxt = es[eid].u + es[eid].v - now;
        if (dis[nxt] > dis[now] + es[eid].w)
        {
            dis[nxt] = dis[now] + es[eid].w;
            es[eid].t = (now == es[eid].u) ? 2 : 1;
            dfs(nxt, eid);
        }
    }
}
int main()
{
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> s >> t;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        es[i] = Edge{u, v, 0, w};
        way[u].push_back(i), way[v].push_back(i);
    }
    dis[s] = 0;
    dfs(s, -1);
    dis[t] = 0;
    dfs(t, -1);
    for (int i = 1; i < n; i++)
    {
        int a = es[i].u, b = es[i].v;
        if (times[a] + times[b] == 3)
        {
            es[i].t = 0;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dis[i];
    }
    cout << ans << endl;
    for (int i = 1; i < n; i++)
    {
        cout << es[i].t;
    }
    return 0;
}