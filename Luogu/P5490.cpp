#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int x, up, down, opt;
};
Edge es[200005];
struct Node
{
    int lc, rc, len, v, t;
};
Node ns[400005];
long long ans;
int n, epos, spos, pos, root, ls[200005];
bool cmp(Edge a, Edge b)
{
    return a.x < b.x;
}
void maketree(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].len = ls[l + 1] - ls[l];
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
    ns[now].len = ns[ns[now].lc].len + ns[ns[now].rc].len;
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].t += k;
        ns[now].v = (ns[now].t ? ns[now].len : ns[ns[now].lc].v + ns[ns[now].rc].v);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    ns[now].v = (ns[now].t ? ns[now].len : ns[ns[now].lc].v + ns[ns[now].rc].v);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        es[++epos] = Edge{a, d, b, 1};
        es[++epos] = Edge{c, d, b, -1};
        ls[++spos] = b, ls[++spos] = d;
    }
    sort(es + 1, es + epos + 1, cmp);
    sort(ls + 1, ls + spos + 1);
    spos = unique(ls + 1, ls + spos + 1) - ls - 1;
    maketree(root, 1, spos);
    for (int i = 1, pre = 0; i <= epos; i++)
    {
        int up = lower_bound(ls + 1, ls + spos + 1, es[i].up) - ls;
        int down = lower_bound(ls + 1, ls + spos + 1, es[i].down) - ls;
        ans += 1ll * (es[i].x - pre) * ns[root].v;
        edit(root, 1, spos, down, up - 1, es[i].opt);
        pre = es[i].x;
    }
    cout << ans << endl;
    return 0;
}