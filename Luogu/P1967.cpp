/*
todo 1.两点间可能有很多方案  题目要求尽可能使路径权值更大
todo   所以先利用prim或者kruskal[代码使用]做出最大生成树
todo 2.路径情况已经唯一  实际走法是x---LCA---y  现在只需找出两点的LCA
todo   这里使用了倍增和前向链表求出LCA
todo 3.模拟实际走法x---LCA---y
todo   找出路径中权值最小的路  该权值为最高称重
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct Way
{
    int x, y, w;
};
Way ways[50005];    //!每条路
int g[10005];       //!每个点所在组
int all[10005];     //!每个点最后一条路
int anc[10005][15]; //!每个点的所有祖先 0父亲 1爷爷...
int dp[10005];      //!每个点深度
int lk[100005][3];  //!每条最大路 0该路目标点 1该路长度 2上一条同源路径编号
bool cmp(Way a, Way b)
{
    return a.w > b.w;
}
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
void make(int x, int step) //!安排祖先关系
{
    dp[x] = step;
    for (int i = 1; i <= log2(dp[x]); i++) //将x的祖先安排到位
    {
        int id = anc[x][i - 1];
        anc[x][i] = anc[id][i - 1];
    }
    for (int i = all[x]; lk[i][0] != 0; i = lk[i][2]) //查找x的子节点
    {
        int id = lk[i][0];
        if (dp[id] == 0)
        {
            anc[id][0] = x;
            make(id, step + 1);
        }
    }
}
int lca(int a, int b) //!求lca
{
    if (dp[b] > dp[a])
    {
        swap(a, b);
    }
    if (dp[a] != dp[b]) //如果a b深度不同 将a提升到b的深度
    {
        for (int i = log2(dp[a] - dp[b]); i >= 0; i--)
        {
            if (dp[a] - pow(2, i) >= dp[b])
            {
                a = anc[a][i];
            }
        }
    }
    if (a == b) //如果此时a b重合
    {
        return a;
    }
    for (int i = log2(dp[a]); i >= 0; i--) //不断向上 寻找lca
    {
        if (anc[a][i] != anc[b][i])
        {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
}
int find(int child, int boss) //!求从child到boss的最小权值
{
    int maxw = 0x3f3f3f3f;
    while (child != boss)
    {
        int fa = anc[child][0];
        int id = all[child];
        while (lk[id][0] != fa)
        {
            id = lk[id][2];
        }
        maxw = min(maxw, lk[id][1]);
        child = fa;
    }
    return maxw;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ways[i].x >> ways[i].y >> ways[i].w;
    }
    sort(ways + 1, ways + 1 + m, cmp);
    int p = 1;
    for (int i = 1; i <= m; i++) //做出最大生成树
    {
        int x = ways[i].x, y = ways[i].y;
        int gx = dfn(x), gy = dfn(y);
        if (gx != gy)
        {
            g[gx] = gy;
            lk[p][0] = y;
            lk[p][1] = ways[i].w;
            lk[p][2] = all[x];
            all[x] = p++;
            lk[p][0] = x;
            lk[p][1] = ways[i].w;
            lk[p][2] = all[y];
            all[y] = p++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == g[i])
        {
            make(i, 1);
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (dfn(x) != dfn(y))
        {
            cout << -1 << endl;
            continue;
        }
        int boss = lca(x, y);
        cout << min(find(x, boss), find(y, boss)) << endl;
    }
    return 0;
}