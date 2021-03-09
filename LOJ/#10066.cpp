#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge
{
    int x, y, d;
    bool operator<(const Edge &another) const
    {
        return d < another.d;
    }
};
Edge es[100005];
int g[500], pos;
void add_edge(int id, int x, int y, int d)
{
    es[id].x = x, es[id].y = y, es[id].d = d;
}
int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int read();
int main()
{
    int n = read();
    //设n+1为虚拟点 表示电站
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
        int w = read();
        add_edge(++pos, n + 1, i, w);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w = read();
            if (i != j)
            {
                add_edge(++pos, i, j, w);
            }
        }
    }
    sort(es + 1, es + 1 + pos);
    int cost = 0;
    for (int i = 1; i <= pos; i++)
    {
        int gx = dfn(es[i].x), gy = dfn(es[i].y);
        if (gx != gy)
        {
            g[gy] = gx;
            cost += es[i].d;
        }
    }
    printf("%d", cost);
    return 0;
}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}