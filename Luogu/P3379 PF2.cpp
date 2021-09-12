#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int dp, sz, zson, fa, head;
    vector<int> son;
};
Node ns[500005];
void dfs(int now, int deep)
{
    ns[now].dp = deep;
    ns[now].sz = 1;
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int s = ns[now].son[i];
        if (s == ns[now].fa)
        {
            continue;
        }
        ns[s].fa = now;
        dfs(s, deep + 1);
        ns[now].sz += ns[s].sz;
        if (ns[ns[now].zson].sz < ns[s].sz)
        {
            ns[now].zson = s;
        }
    }
}
void dfs2(int now, int hd)
{
    ns[now].head = hd;
    if (ns[now].zson)
    {
        dfs2(ns[now].zson, hd);
    }
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int s = ns[now].son[i];
        if (s == ns[now].fa || s == ns[now].zson)
        {
            continue;
        }
        dfs2(s, s);
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
    if (ns[x].dp < ns[y].dp)
    {
        swap(x, y);
    }
    return y;
}
int main()
{
    int n, m, root;
    cin >> n >> m >> root;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ns[x].son.push_back(y);
        ns[y].son.push_back(x);
    }
    dfs(root, 1);
    dfs2(root, root);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}