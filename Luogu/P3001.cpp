#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int to;
    long double w;
};
vector<Edge> es[2005];
queue<int> q;
int n, m, a, b, cnt[2005], inq[2005];
long double v, dis[2005];
int main()
{
    cin >> n >> m >> v >> a >> b;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        long double z;
        cin >> x >> y >> z;
        es[x].push_back(Edge{y, z});
    }
    fill(dis + 1, dis + 1 + n, 1e18);
    q.push(a), cnt[a]++, inq[a] = 1, dis[a] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop(), inq[now] = 0;
        for (Edge e : es[now])
        {
            int nxt = e.to;
            long double w = e.w;
            if (dis[now] * w < dis[nxt])
            {
                dis[nxt] = dis[now] * w;
                if (inq[nxt] == 0)
                {
                    inq[nxt] = 1, q.push(nxt), cnt[nxt]++;
                    if (cnt[nxt] >= n)
                    {
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(6) << dis[b] * v << endl;
    return 0;
}