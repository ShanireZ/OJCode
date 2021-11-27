#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
int n, m, pos, last[300005], inq[300005], d[300005];
struct Edge
{
    int to, w, pre;
};
Edge es[4000005];
queue<int> q;
void addEdge(int u, int v, int w)
{
    es[++pos].pre = last[u];
    es[pos].to = v, es[pos].w = w;
    last[u] = pos;
}
void spfa(int st)
{
    d[st] = 0, inq[st] = 1;
    q.push(st);
    while (q.size())
    {
        int from = q.front();
        inq[from] = 0;
        q.pop();
        for (int i = last[from]; i != 0; i = es[i].pre)
        {
            int to = es[i].to, w = es[i].w;
            if (d[to] < d[from] + w)
            {
                d[to] = d[from] + w;
                if (inq[to] == 0)
                {
                    inq[to] = 1;
                    q.push(to);
                }
            }
        }
    }
}
int main()
{
    n = read(), m = read();
    fill(d, d + 300005, -0x3f3f3f3f);
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        addEdge(i, i + n, -x);
        addEdge(i + n, i + n * 2, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read(), z = read();
        addEdge(x, y, 0);
        addEdge(x + n, y + n, 0);
        addEdge(x + n * 2, y + n * 2, 0);
        if (z == 2) //双向
        {
            addEdge(y, x, 0);
            addEdge(y + n, x + n, 0);
            addEdge(y + n * 2, x + n * 2, 0);
        }
    }
    spfa(1);
    printf("%d\n", d[n * 3]);
    return 0;
}