#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define maxsz 300005
int read();
struct Node
{
    int dp, sz, fa, zson, head;
    long long v;
    vector<int> son;
};
Node ns[maxsz];
int go[maxsz];
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
void update(int now)
{
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int son = ns[now].son[i];
        if (son == ns[now].fa)
        {
            continue;
        }
        update(son);
        ns[now].v += ns[son].v;
    }
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        go[i] = read();
    }
    for (int i = 1; i < n; i++)
    {
        int a = read(), b = read();
        ns[a].son.push_back(b);
        ns[b].son.push_back(a);
    }
    dfs1(go[1], 1);
    dfs2(go[1], go[1]);
    for (int i = 1; i < n; i++)
    {
        int anc = lca(go[i], go[i + 1]);
        ns[go[i]].v++, ns[go[i + 1]].v++;
        ns[anc].v--, ns[ns[anc].fa].v--;
    }
    update(go[1]);
    for (int i = 1; i <= n; i++)
    {
        if (i == go[1])
        {
            printf("%lld\n", ns[i].v);
        }
        else
        {
            printf("%lld\n", ns[i].v - 1);
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