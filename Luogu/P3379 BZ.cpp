#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int dp[500005], anc[500005][25];
int last[500005], to[1000005], pre[1000005]; // 链式前向星
void make(int now, int step)
{
    dp[now] = step;
    for (int i = 1; i <= log2(dp[now]); i++) // 将x的祖先安排到位
    {
        int id = anc[now][i - 1];
        anc[now][i] = anc[id][i - 1];
    }
    for (int i = last[now]; i != 0; i = pre[i]) // 查找x的子节点
    {
        int id = to[i];
        if (dp[id] == 0)
        {
            anc[id][0] = now;
            make(id, step + 1);
        }
    }
}
void lca(int a, int b)
{
    if (dp[b] > dp[a])
    {
        swap(a, b);
    }
    if (dp[a] != dp[b]) // 如果a b深度不同 将a提升到b的深度
    {
        for (int i = log2(dp[a] - dp[b]); i >= 0; i--)
        {
            if (dp[a] - pow(2, i) >= dp[b])
            {
                a = anc[a][i];
            }
        }
    }
    if (a == b) // 如果此时a b重合
    {
        printf("%d\n", a);
        return;
    }
    for (int i = log2(dp[a]); i >= 0; i--) // 不断向上 寻找lca
    {
        if (anc[a][i] != anc[b][i])
        {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    printf("%d\n", anc[a][0]);
}
int rd() // 正数快读
{
    char ch = getchar();
    int x = 0;
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x * 10) + (ch - '0');
        ch = getchar();
    }
    return x;
}
void addEdge(int u, int v, int eid)
{
    to[eid] = v, pre[eid] = last[u];
    last[u] = eid;
}
int main()
{
    int n = rd(), m = rd(), s = rd(), cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int x = rd(), y = rd();
        addEdge(x, y, ++cnt);
        addEdge(y, x, ++cnt);
    }
    make(s, 1);
    for (int i = 1; i <= m; i++)
    {
        int x = rd(), y = rd();
        lca(x, y);
    }
    return 0;
}