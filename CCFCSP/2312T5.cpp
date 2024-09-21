#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int n, m, l, k, ans, c[105], u[5005], v[5005], read();
struct Edge
{
    int v, w;
};
vector<Edge> es[105], res[105];
struct Sta
{
    int sta, dis;
};
Sta s1[30005], s2[30005];
unordered_map<int, int> s[105], rs[105];
bool cmp(Sta a, Sta b)
{
    return a.dis > b.dis;
}
void dfs(int now, int step, int status, int dis)
{
    s[now][status] = max(dis, s[now][status]);
    if (step == l / 2)
    {
        return;
    }
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (status & (1 << c[nxt]))
        {
            continue;
        }
        dfs(nxt, step + 1, status | (1 << c[nxt]), dis + e.w);
    }
}
void rdfs(int now, int step, int status, int dis)
{
    rs[now][status] = max(dis, rs[now][status]);
    if (step == l - l / 2)
    {
        return;
    }
    for (Edge e : res[now])
    {
        int nxt = e.v;
        if (status & (1 << c[nxt]))
        {
            continue;
        }
        rdfs(nxt, step + 1, status | (1 << c[nxt]), dis + e.w);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    n = read(), m = read(), l = read() + 1, k = read();
    for (int i = 0; i < n; i++)
    {
        c[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        u[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        v[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        int d = read();
        es[u[i]].push_back(Edge{v[i], d}), res[v[i]].push_back(Edge{u[i], d});
    }
    dfs(0, 1, 1 << c[0], 0), rdfs(n - 1, 1, 1 << c[n - 1], 0);
    for (int i = 0; i < n; i++)
    {
        int p1 = 0, p2 = 0;
        for (auto x : s[i])
        {
            s1[++p1] = Sta{x.first, x.second};
        }
        for (auto x : rs[i])
        {
            s2[++p2] = Sta{x.first, x.second};
        }
        sort(s1 + 1, s1 + p1 + 1, cmp), sort(s2 + 1, s2 + p2 + 1, cmp);
        for (int j = 1; j <= p1; j++)
        {
            if (s1[j].dis + s2[1].dis <= ans)
            {
                break;
            }
            for (int k = 1; k <= p2; k++)
            {
                if (s1[j].dis + s2[k].dis <= ans)
                {
                    break;
                }
                if ((s1[j].sta & s2[k].sta) == (1 << c[i]))
                {
                    ans = max(ans, s1[j].dis + s2[k].dis);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
// TAG: 卡常 meet in the middle 状态压缩 折半搜索