#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int read();
#define maxsz 100005
struct Node
{
    int fa, zson, dp, head, sz;
    vector<int> son;
};
Node ns[maxsz];
void dfs1(int now, int dp)
{
    ns[now].sz = 1;
    ns[now].dp = dp;
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int son = ns[now].son[i];
        if (son == ns[now].fa)
        {
            continue;
        }
        ns[son].fa = now;
        dfs1(son, dp + 1);
        ns[now].sz += ns[son].sz;
        if (ns[ns[now].zson].sz < ns[son].sz)
        {
            ns[now].zson = son;
        }
    }
}
void dfs2(int now, int head)
{
    ns[now].head = head;
    if (ns[now].zson == 0)
    {
        return;
    }
    dfs2(ns[now].zson, head);
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int son = ns[now].son[i];
        if (son == ns[now].fa || son == ns[now].zson)
        {
            continue;
        }
        dfs2(son, son);
    }
}
int lca(int x, int y)
{
    int hx = ns[x].head, hy = ns[y].head;
    while (hx != hy)
    {
        if (ns[hx].dp < ns[hy].dp)
        {
            swap(x, y);
            swap(hx, hy);
        }
        x = ns[hx].fa;
        hx = ns[x].head;
    }
    return (ns[x].dp < ns[y].dp) ? x : y;
}
int main()
{
    int n = read(), q = read(), root = 1;
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        ns[u].son.push_back(v);
        ns[v].son.push_back(u);
    }
    dfs1(root, 1);
    dfs2(root, root);
    for (int i = 1; i <= q; i++)
    {
        //如果x y较深的那个在另外两点路径上
        //那么必然有x == lca(x, c) || x == lca(x, d)
        int a = read(), b = read(), c = read(), d = read();
        int x = lca(a, b), y = lca(c, d);
        if (ns[x].dp < ns[y].dp)
        {
            swap(x, y);
            swap(a, c);
            swap(b, d);
        }
        if (x == lca(x, c) || x == lca(x, d))
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
    return 0;
}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
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