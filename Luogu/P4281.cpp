#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int read();
#define maxsz 500005
struct Node
{
    int fa, sz, dp, head, zson;
    vector<int> son;
};
Node ns[maxsz];
void dfs1(int now, int dp)
{
    ns[now].dp = dp;
    ns[now].sz = 1;
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
    while (ns[x].head != ns[y].head)
    {
        if (ns[ns[x].head].dp < ns[ns[y].head].dp)
        {
            swap(x, y);
        }
        x = ns[ns[x].head].fa;
    }
    return (ns[x].dp < ns[y].dp) ? x : y;
}
int main()
{
    int n = read(), m = read(), root = 1;
    for (int i = 1; i < n; i++)
    {
        int a = read(), b = read();
        ns[a].son.push_back(b);
        ns[b].son.push_back(a);
    }
    dfs1(root, 1);
    dfs2(root, root);
    for (int i = 1; i <= m; i++)
    {
        //集合位置必定有2个重复 也必定是最深的lca
        int a = read(), b = read(), c = read();
        int x = lca(a, b), y = lca(a, c), z = lca(b, c);
        if (ns[x].dp < ns[y].dp)
        {
            swap(x, y);
            swap(b, c);
        }
        if (ns[x].dp < ns[z].dp)
        {
            swap(x, z);
            swap(a, c);
        }
        //分多种情况，可以推导一下
        printf("%d %d\n", x, ns[a].dp + ns[b].dp + ns[c].dp - ns[x].dp - ns[y].dp * 2);
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