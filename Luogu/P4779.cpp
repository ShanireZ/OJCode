#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 100005
struct Path
{
    int t, d;
    bool operator<(const Path np) const
    {
        return d > np.d;
    }
};
priority_queue<Path> q;
int to[MX * 2], w[MX * 2], pre[MX * 2], last[MX], dis[MX];
int n, m, s;
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> w[i];
        to[i] = v, pre[i] = last[u];
        last[u] = i;
    }
    memset(dis, 0x3f, sizeof(dis));
    q.push(Path{s, 0});
    while (q.size())
    {
        int f = q.top().t, d = q.top().d;
        q.pop();
        if (dis[f] != 0x3f3f3f3f)
        {
            continue;
        }
        dis[f] = d;
        for (int i = last[f]; i; i = pre[i])
        {
            int t = to[i];
            if (dis[t] != 0x3f3f3f3f)
            {
                continue;
            }
            q.push(Path{t, d + w[i]});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}