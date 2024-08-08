#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int id, v;
    bool operator<(const Node &oth) const // 按值平衡,所以每次插入右下
    {
        return v < oth.v;
    }
};
Node ns[MX];
int root, last, n, lc[MX], rc[MX], fa[MX];
bool cmp(Node a, Node b)
{
    return a.id < b.id;
}
void dfs(int now)
{
    cout << ns[now].v << ' ';
    if (lc[now])
    {
        dfs(lc[now]);
    }
    if (rc[now])
    {
        dfs(rc[now]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
        ns[i].id = i;
    }
    sort(ns + 1, ns + 1 + n);
    last = root = ns[1].id;
    for (int i = 2; i <= n; i++)
    {
        int now = last, ok = 1;
        while (now > ns[i].id) // 按id份层,所以每次按id上下
        {
            if (fa[now] == 0)
            {
                root = ns[i].id;
                lc[ns[i].id] = now, fa[now] = ns[i].id, ok = 0;
                break;
            }
            now = fa[now];
        }
        if (ok)
        {
            fa[ns[i].id] = now, lc[ns[i].id] = rc[now];
            fa[rc[now]] = ns[i].id, rc[now] = ns[i].id;
        }
        last = ns[i].id;
    }
    sort(ns + 1, ns + 1 + n, cmp);
    dfs(root);
    return 0;
}