#include <iostream>
#include <vector>
using namespace std;
#define MX 80005
struct Edge
{
    int t, mr, maxmr;
};
vector<Edge> es[MX], scc[MX];
int n, m, st, spos, npos, gpos;
int g[MX], s[MX], dfn[MX], low[MX], dp[MX], ans[MX];
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    s[++spos] = now;
    for (int i = 0; i < es[now].size(); i++)
    {
        int t = es[now][i].t;
        if (dfn[t] == 0)
        {
            tarjan(t);
            low[now] = min(low[now], low[t]);
        }
        else if (g[t] == 0)
        {
            low[now] = min(low[now], dfn[t]);
        }
    }
    if (dfn[now] == low[now])
    {
        ++gpos;
        while (s[spos] != now)
        {
            g[s[spos--]] = gpos;
        }
        g[s[spos--]] = gpos;
    }
}
void remake()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < es[i].size(); j++)
        {
            int t = es[i][j].t;
            if (g[i] == g[t])
            {
                dp[g[i]] += es[i][j].maxmr;
            }
            else
            {
                scc[g[i]].push_back(Edge{g[t], es[i][j].mr, 0});
            }
        }
    }
}
int dfs(int now)
{
    if (ans[now])
    {
        return ans[now];
    }
    int ex = 0;
    for (int i = 0; i < scc[now].size(); i++)
    {
        int t = scc[now][i].t, mr = scc[now][i].mr;
        ex = max(ex, dfs(t) + mr);
    }
    return ans[now] = dp[now] + ex;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int f, t, mr, ex;
        double x; // 这个太坑了
        cin >> f >> t >> mr >> x;
        ex = x * 10;
        int now = mr, tot = 0;
        while (now)
        {
            tot += now;
            now = now * ex / 10;
        }
        es[f].push_back(Edge{t, mr, tot});
    }
    cin >> st;
    tarjan(st);
    remake();
    cout << dfs(g[st]) << endl;
    return 0;
}