#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int to, w;
};
vector<Edge> es[200005];
vector<int> g[200005];
int gpos, n, m, ok, lt[200005], vis[2][200005][35], val[2][200005][35], res[200005][35];
void check(int now)
{
    lt[now] = 1, g[gpos].emplace_back(now);
    for (Edge e : es[now])
    {
        if (lt[e.to] == 0)
        {
            check(e.to);
        }
    }
}
void dfs(int now, int pos, int opt)
{
    vis[opt][now][pos] = 1;
    for (int i = 0; i < (int)es[now].size() && ok; i++)
    {
        int nxt = es[now][i].to, w = es[now][i].w;
        if (vis[opt][nxt][pos] == 0)
        {
            val[opt][nxt][pos] = (((w >> pos) & 1) ^ val[opt][now][pos]);
            dfs(nxt, pos, opt);
        }
        else if (val[opt][nxt][pos] != (((w >> pos) & 1) ^ val[opt][now][pos]))
        {
            ok = 0;
            return;
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        es[a].emplace_back(Edge{b, c}), es[b].emplace_back(Edge{a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        if (lt[i] == 0)
        {
            gpos++;
            check(i);
        }
    }
    for (int gi = 1; gi <= gpos; gi++)
    {
        for (int pos = 0; pos < 30; pos++)
        {
            int c0 = 1e9, c1 = 1e9;
            ok = 1, val[0][g[gi].front()][pos] = 0, dfs(g[gi].front(), pos, 0);
            if (ok)
            {
                c0 = 0;
                for (int id : g[gi])
                {
                    c0 += val[0][id][pos];
                }
            }
            ok = 1, val[1][g[gi].front()][pos] = 1, dfs(g[gi].front(), pos, 1);
            if (ok)
            {
                c1 = 0;
                for (int id : g[gi])
                {
                    c1 += val[1][id][pos];
                }
            }
            if (c0 == 1e9 && c1 == 1e9)
            {
                cout << -1 << endl;
                return 0;
            }
            for (int id : g[gi])
            {
                res[id][pos] = (c0 <= c1 ? val[0][id][pos] : val[1][id][pos]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        for (int j = 29; j >= 0; j--)
        {
            num = (num << 1) + res[i][j];
        }
        cout << num << " ";
    }
    return 0;
}