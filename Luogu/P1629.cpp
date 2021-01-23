#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int done, dis, cnt;
    vector<int> to;
};
Node g[1000005];
struct Nodeq
{
    int id, w;
};
struct cmp
{
    bool operator()(Nodeq a, Nodeq b)
    {
        return a.w > b.w;
    }
};
priority_queue<Nodeq, vector<Nodeq>, cmp> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i].dis = 0x3f3f3f3f;
    }
    g[1].dis = 0, g[1].cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].to.push_back(v);
        g[v].to.push_back(u);
    }
    Nodeq tmp;
    tmp.id = 1, tmp.w = 0;
    q.push(tmp);
    while (q.size())
    {
        int from = q.top().id;
        int dfrom = q.top().w;
        q.pop();
        if (g[from].done == 0)
        {
            g[from].done = 1;
            for (int i = 0; i < g[from].to.size(); i++)
            {
                int to = g[from].to[i];
                if (dfrom + 1 < g[to].dis)
                {
                    g[to].dis = dfrom + 1;
                    g[to].cnt = g[from].cnt % 100003;
                    Nodeq tmp;
                    tmp.id = to, tmp.w = g[to].dis;
                    q.push(tmp);
                }
                else if (dfrom + 1 == g[to].dis)
                {
                    g[to].cnt = (g[to].cnt + g[from].cnt) % 100003;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << g[i].cnt << endl;
    }
    return 0;
}