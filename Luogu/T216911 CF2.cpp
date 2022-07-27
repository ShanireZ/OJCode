#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Quest
{
    int qid, h;
};
vector<Quest> qs[MX];
int n, m, pos, root, cnt, ans[MX], vis[MX];
vector<int> to[MX];
struct Node
{
    int v, lc, rc;
};
Node ns[MX * 4];
void update(int now)
{
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void maketree(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
    update(now);
}
void edit(int now, int l, int r, int x)
{
    if (l == r)
    {
        ns[now].v++;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, x);
    }
    update(now);
}
int query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    int tot = 0, mid = (l + r) / 2;
    if (x <= mid)
    {
        tot += query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        tot += query(ns[now].rc, mid + 1, r, x, y);
    }
    return tot;
}
void dfs(int now, int dp)
{
    vis[now] = 1;
    for (int i = 0; i < qs[now].size(); i++)
    {
        ans[qs[now][i].qid] = query(root, 1, n, qs[now][i].h, n);
    }
    edit(root, 1, n, dp);
    for (int i = 0; i < to[now].size(); i++)
    {
        int t = to[now][i];
        if (vis[t])
        {
            continue;
        }
        dfs(t, dp + 1);
    }
    for (int i = 0; i < qs[now].size(); i++)
    {
        ans[qs[now][i].qid] = query(root, 1, n, qs[now][i].h, n) - ans[qs[now][i].qid];
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y), to[y].push_back(x);
    }
    int h = n + 1;
    for (int i = 1; i <= m; i++)
    {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1)
        {
            h = x;
        }
        else
        {
            qs[x].push_back(Quest{++pos, h});
        }
    }
    maketree(root, 1, n);
    dfs(1, 1);
    for (int i = 1; i <= pos; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}