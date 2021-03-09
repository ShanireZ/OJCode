#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 3e5 + 5, maxj = 20, inf = 0x7fffffff;
struct edge
{
    int u, v, w, usd;
} e[maxm];
int heade[maxn], ev[maxm], ew[maxm], nexte[maxm];
int father[maxn], dep[maxn];
int fa[maxn][maxj], maxv[maxn][maxj], maxv2[maxn][maxj];
int n, m, root, now = 0, cnt = 0;
void add_edge(int u, int v, int w)
{
    now++;
    ev[now] = v;
    ew[now] = w;
    nexte[now] = heade[u];
    heade[u] = now;
}
int cmp(edge a, edge b) { return a.w < b.w; }
int find(int x) { return father[x] < 0 ? x : father[x] = find(father[x]); }
bool union_set(int u, int v, int w)
{
    int x = find(u), y = find(v);
    if (x == y)
    {
        return 0;
    }
    //按秩合并 小的合并到大的
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
    //加边构建MST树-MST重构树
    add_edge(u, v, w);
    add_edge(v, u, w);
    cnt++;
    return 1;
}
void dfs(int ui)
{
    for (int i = heade[ui]; i != 0; i = nexte[i]) //深搜整棵MST
    {
        int vi = ev[i];
        int wi = ew[i];
        if (vi == fa[ui][0]) //是返祖边时忽略
        {
            continue;
        }
        //fa[i][j]表示从点i向上2^j步是哪个点 用来lca
        fa[vi][0] = ui;
        //maxv[i][j]表示从点i向上2^j步最大瓶颈是多少
        maxv[vi][0] = wi;
        maxv2[vi][0] = -inf;
        //dep表示点的深度 用来lca
        dep[vi] = dep[ui] + 1;
        dfs(vi);
    }
}
pair<int, int> bjdx(int a, int b, int c, int d)
{
    pair<int, int> tmp;
    int all[5] = {0, a, b, c, d};
    sort(all + 1, all + 5);
    tmp.first = all[4];
    for (int i = 3; i >= 1; i--)
    {
        if (all[i] == all[4])
        {
            continue;
        }
        tmp.second = all[i];
        break;
    }
    return tmp;
}
void init()
{
    for (int j = 1; (1 << j) <= n; j++) //枚举向上的步数
    {
        for (int i = 1; i <= n; i++)
        {
            if (fa[i][j - 1]) //如果前一步存在
            {
                //倍增
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
                //维护最大瓶颈
                pair<int, int> tmp = bjdx(maxv[i][j - 1], maxv[fa[i][j - 1]][j - 1], maxv2[i][j - 1], maxv2[fa[i][j - 1]][j - 1]);
                maxv[i][j] = tmp.first;
                maxv2[i][j] = tmp.second;
            }
        }
    }
}
pair<int, int> query(int u, int v)
{
    int t;
    pair<int, int> tmp(-inf, -inf); //first-最大 second-次大
    if (dep[u] < dep[v])            //保证u的深度>= v的深度
    {
        swap(u, v);
    }
    //不同深度就拉齐深度
    t = (int)(log(dep[u]) / log(2));
    for (int j = t; j >= 0; j--)
    {
        if (dep[u] - (1 << j) >= dep[v])
        {
            //维护路径上的最大瓶颈
            tmp = bjdx(tmp.first, tmp.second, maxv[u][j], maxv2[u][j]);
            u = fa[u][j];
        }
    }
    //拉起后重合了 说明这个位置就是lca
    if (u == v)
    {
        return tmp;
    }
    //寻找lca
    for (int j = t; j >= 0; j--)
    {
        if (fa[u][j] && fa[u][j] != fa[v][j])
        {
            tmp = bjdx(tmp.first, tmp.second, maxv[u][j], maxv2[u][j]);
            tmp = bjdx(tmp.first, tmp.second, maxv[v][j], maxv2[v][j]);
            u = fa[u][j];
            v = fa[v][j];
        }
    }
    //u v现在全是lca的子节点了
    tmp = bjdx(tmp.first, tmp.second, maxv[u][0], maxv[v][0]);
    return tmp;
}
int main()
{
    cin >> n >> m;
    root = (1 + n) / 2; //用中间编号当作MST的root
    //father用来搞并查集，但用的是路径压缩+按秩合并。
    //小弟们都是存大哥，大哥存组织人员的个数
    memset(father, -1, sizeof(father));
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    sort(e + 1, e + m + 1, cmp);
    long long tot = 0;
    for (int i = 1; i <= m; i++)
    {
        if (e[i].u == e[i].v)
        {
            e[i].usd = 1;
            continue;
        }
        if (union_set(e[i].u, e[i].v, e[i].w))
        {
            tot += e[i].w;
            e[i].usd = 1;
        }
        if (cnt == n - 1) //kruskal剪枝
        {
            break;
        }
    }
    //倍增初始化
    dfs(root);
    init();
    int ans = inf;
    for (int i = 1; i <= m; i++)
    {
        if (e[i].usd == 0)
        {
            pair<int, int> tmp = query(e[i].u, e[i].v);
            if (e[i].w == tmp.first)
            {
                if (tmp.second == -inf)
                {
                    continue;
                }
                ans = min(ans, e[i].w - tmp.second);
            }
            else
            {
                ans = min(ans, e[i].w - tmp.first);
            }
        }
    }
    printf("%lld", tot + ans);
    return 0;
}