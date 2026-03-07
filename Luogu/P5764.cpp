#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int to, w;
};
vector<Edge> es[50005];
struct Plan
{
    int ed, len;
    bool operator<(Plan oth) const
    {
        return len > oth.len;
    }
};
priority_queue<Plan> q;
int n, m, ans = 1e9, dis[10][50005], p[10], a[5] = {2, 3, 4, 5, 6};
int main()
{
    cin >> n >> m >> p[2] >> p[3] >> p[4] >> p[5] >> p[6];
    p[1] = 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= 6; i++)
    {
        int s = p[i];
        q.push(Plan{s, 0});
        while (q.size())
        {
            int now = q.top().ed, d = q.top().len;
            q.pop();
            if (d < dis[i][now])
            {
                dis[i][now] = d;
                for (Edge e : es[now])
                {
                    if (dis[i][now] + e.w < dis[i][e.to])
                    {
                        q.push(Plan{e.to, dis[i][now] + e.w});
                    }
                }
            }
        }
    }
    do
    {
        int x = p[a[0]], b = p[a[1]], c = p[a[2]], d = p[a[3]], e = p[a[4]];
        int sum = dis[1][x] + dis[a[0]][b] + dis[a[1]][c] + dis[a[2]][d] + dis[a[3]][e];
        ans = min(ans, sum);
    } while (next_permutation(a, a + 5));
    cout << ans << endl;
    return 0;
}