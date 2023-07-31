#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int d, done;       //! d:点s到该点距离 done:是否已经确定最短路径
    vector<int> to, w; //! to:边的目标点编号 w:该边权重
};
Node g[10005];
struct Way
{
    int id, w; //! id:更新的点的编号 w:更新的点到s的距离
    bool operator<(const Way another) const
    {
        return w > another.w;
    }
};
priority_queue<Way> q;
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        g[i].d = INT_MAX;
    }
    g[s].d = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].to.push_back(v);
        g[u].w.push_back(w);
    }
    q.push(Way{s, 0});
    while (q.size())
    {
        int from = q.top().id;
        int dfrom = q.top().w;
        q.pop();
        if (g[from].done == 0) //? 如果当前点的最短距离还未确定
        {
            g[from].done = 1;
            for (int i = 0; i < g[from].to.size(); i++)
            {
                int to = g[from].to[i];
                int dto = g[from].w[i];
                if (dto + dfrom < g[to].d)
                {
                    g[to].d = dto + dfrom;
                    q.push(Way{to, g[to].d});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << g[i].d << " ";
    }
    return 0;
}