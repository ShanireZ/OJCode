#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int done, d;
    vector<int> to;
    vector<int> w;
};
Node g[2][1005];
struct Way
{
    int id, w;
};
struct cmp
{
    bool operator()(Way a, Way b)
    {
        return a.w > b.w;
    }
};
priority_queue<Way, vector<Way>, cmp> q;
int main()
{
    int n, m, tot = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[0][i].d = g[1][i].d = 0x3f3f3f3f;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[0][u].to.push_back(v);
        g[0][u].w.push_back(w);
        g[1][v].to.push_back(u);
        g[1][v].w.push_back(w);
    }
    for (int k = 0; k < 2; k++)
    {
        Way st;
        st.id = 1, st.w = 0;
        q.push(st);
        while (q.size())
        {
            int from = q.top().id;
            int dfrom = q.top().w;
            q.pop();
            if (g[k][from].done == 0)
            {
                g[k][from].done = 1;
                for (int i = 0; i < g[k][from].to.size(); i++)
                {
                    int to = g[k][from].to[i];
                    int dto = g[k][from].w[i];
                    if (dfrom + dto < g[k][to].d)
                    {
                        g[k][to].d = dfrom + dto;
                        Way tmp;
                        tmp.id = to, tmp.w = g[k][to].d;
                        q.push(tmp);
                    }
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            tot += g[k][i].d;
        }
    }
    cout << tot;
    return 0;
}