#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int read();
int n, m, d, vis[155][505];
double times[155][505]; //分层图 times[i][j]表示 到达点i时速度为j的最小时间
vector<int> way;
struct Edge
{
    int to, v, l;
    Edge(int To, int V, int L)
    {
        to = To, v = V, l = L;
    }
};
vector<Edge> es[155];
struct Path
{
    int id, v;
    double t;
    Path(int Id = 0, int V = 0, double T = 0)
    {
        id = Id, v = V, t = T;
    }
    bool operator<(const Path ano) const
    {
        return t > ano.t;
    }
} pt[155][505];
void dijkstra()
{
    priority_queue<Path> q;
    q.push(Path(0, 70, 0));
    times[0][70] = 0;
    while (q.size())
    {
        int from = q.top().id;
        int fv = q.top().v;
        q.pop();
        if (vis[from][fv])
        {
            continue;
        }
        vis[from][fv] = 1;
        for (int i = 0; i < es[from].size(); i++)
        {
            int to = es[from][i].to, l = es[from][i].l, tv = es[from][i].v;
            if (tv != 0) //新速度
            {
                if (times[to][tv] > times[from][fv] + (1.0 * l / tv))
                {
                    times[to][tv] = times[from][fv] + (1.0 * l / tv);
                    pt[to][tv] = Path(from, fv, 0); //记录最快路径
                    q.push(Path(to, tv, times[to][tv]));
                }
            }
            else //旧速度
            {
                if (times[to][fv] > times[from][fv] + (1.0 * l / fv))
                {
                    times[to][fv] = times[from][fv] + (1.0 * l / fv);
                    pt[to][fv] = Path(from, fv, 0);
                    q.push(Path(to, fv, times[to][fv]));
                }
            }
        }
    }
}
int main()
{
    n = read(), m = read(), d = read();
    for (int i = 0; i < n; i++) //初始化
    {
        for (int j = 0; j <= 500; j++)
        {
            times[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), v = read(), l = read();
        es[a].push_back(Edge(b, v, l));
    }
    dijkstra();
    int mv = 1;
    for (int i = 1; i <= 500; i++) //遍历times[d][all] 找到最小时间
    {
        if (times[d][i] < times[d][mv])
        {
            mv = i;
        }
    }
    way.push_back(d);
    int p = d;
    while (p) //从终点回溯到起点
    {
        Path now = pt[p][mv];
        p = now.id;
        mv = now.v;
        way.push_back(p);
    }
    for (int i = way.size() - 1; i >= 0; i--)
    {
        printf("%d ", way[i]);
    }
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}