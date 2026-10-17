#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, maxm = 2e5 + 10, maxj = 17, inf = 0x7fffffff;
struct edge
{
    int u, v, w;
} e[maxm];
int heade[maxn], ev[maxm], ew[maxm], nexte[maxm];
int father[maxn], dep[maxn];
int fa[maxn][maxj], maxv[maxn][maxj];
int n, m, q, root, tot = 0, num = 0;
void add_edge(int u, int v, int w)
{
    tot++;
    ev[tot] = v;
    ew[tot] = w;
    nexte[tot] = heade[u];
    heade[u] = tot;
}
int cmp(edge a, edge b) { return a.w < b.w; }
int find(int x) { return father[x] < 0 ? x : father[x] = find(father[x]); }
void union_set(int u, int v, int w)
{
    int x = find(u), y = find(v);
    if (x == y)
    {
        return;
    }
    //按秩合併 小的合併到大的
    if (-father[x] > -father[y])
    {
        father[x] += father[y];
        father[y] = x;
    }
    else
    {
        father[y] += father[x];
        father[x] = y;
    }
    //加邊建置MST樹-MST重構樹
    add_edge(u, v, w);
    add_edge(v, u, w);
    num++;
}
void dfs(int ui)
{
    for (int i = heade[ui]; ~i; i = nexte[i]) //深搜整棵MST
    {
        int vi = ev[i];
        int wi = ew[i];
        if (vi == fa[ui][0]) //是返祖邊時忽略
        {
            continue;
        }
        //fa[i][j]表示從點i向上2^j步是哪個點 用來lca
        fa[vi][0] = ui;
        //maxv[i][j]表示從點i向上2^j步最大瓶頸是多少
        maxv[vi][0] = wi;
        //dep表示點的深度 用來lca
        dep[vi] = dep[ui] + 1;
        dfs(vi);
    }
}
void init()
{
    for (int j = 1; (1 << j) <= n; j++) //枚舉向上的步數
    {
        for (int i = 1; i <= n; i++)
        {
            if (fa[i][j - 1]) //如果前一步存在
            {
                //倍增
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
                //維護最大瓶頸
                maxv[i][j] = max(maxv[i][j - 1], maxv[fa[i][j - 1]][j - 1]);
            }
        }
    }
}
int query(int u, int v)
{
    int i, j, t, tmp = -inf;
    if (dep[u] < dep[v]) //保證u的深度>= v的深度
    {
        swap(u, v);
    }
    //不同深度就拉齊深度
    t = (int)(log(dep[u]) / log(2));
    for (j = t; j >= 0; j--)
    {
        if (dep[u] - (1 << j) >= dep[v])
        {
            //維護路徑上的最大瓶頸
            tmp = max(tmp, maxv[u][j]);
            u = fa[u][j];
        }
    }
    //拉起後重合了 說明這個位置就是lca
    if (u == v)
    {
        return tmp;
    }
    //尋找lca
    for (j = t; j >= 0; j--)
    {
        if (fa[u][j] && fa[u][j] != fa[v][j])
        {
            tmp = max(tmp, max(maxv[u][j], maxv[v][j]));
            u = fa[u][j];
            v = fa[v][j];
        }
    }
    //u v現在全是lca的子節點了
    return max(tmp, max(maxv[u][0], maxv[v][0]));
}
int main()
{
    int i, j, u, v, w;
    cin >> n >> m >> q;
    root = (1 + n) >> 1; //用中間編號當作MST的root
    memset(heade, -1, sizeof(heade));
    //father用來搞並查集，但用的是路徑壓縮+按秩合併。
    //小弟們都是存大哥，大哥存組織人員的個數
    memset(father, -1, sizeof(father));
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    sort(e + 1, e + m + 1, cmp);
    for (i = 1; i <= m; i++)
    {
        u = e[i].u;
        v = e[i].v;
        w = e[i].w;
        union_set(u, v, w);
        if (num >= n - 1) //kruskal剪枝
        {
            break;
        }
    }
    //倍增初始化
    dfs(root);
    init();
    for (i = 1; i <= q; i++)
    {
        scanf("%d%d", &u, &v);
        if (find(u) != find(v))
        {
            printf("-1\n");
            continue;
        }
        //u到v 相當於u v到lca(u, v)
        printf("%d\n", query(u, v));
    }
    return 0;
}