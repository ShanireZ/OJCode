#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> to[3005];
int dis[3005][3];
struct Path
{
    int t, w;
    bool operator<(const Path oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> q;
void dijkstra(int mode, int st)
{
    q.push(Path{st, 0});
    while (q.size())
    {
        Path now = q.top();
        q.pop();
        if (dis[now.t][mode] != 0x3f3f3f3f)
        {
            continue;
        }
        dis[now.t][mode] = now.w;
        for (int i = 0; i < to[now.t].size(); i++)
        {
            int nxt = to[now.t][i];
            if (dis[now.t][mode] + 1 < dis[nxt][mode])
            {
                q.push(Path{nxt, dis[now.t][mode] + 1});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y), to[y].push_back(x);
    }
    int s1, t1, s2, t2;
    cin >> s1 >> t1 >> s2 >> t2;
    memset(dis, 0x3f, sizeof(dis));
    dijkstra(0, 1);
    dijkstra(1, s1);
    dijkstra(2, s2);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        if (t1 >= dis[i][0] + dis[i][1] && t2 >= dis[i][0] + dis[i][2])
        {
            ans = min(ans, dis[i][0] + dis[i][1] + dis[i][2]);
        }
    }
    ans = (ans == m || ans == 0x3f3f3f3f) ? -1 : m - ans;
    cout << ans << endl;
    return 0;
}