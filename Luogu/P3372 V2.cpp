#include <iostream>
using namespace std;
struct Node
{
    int lc, rc;
    long long v, tag;
};
Node ns[400005];
long long a[100005];
int pos, root;
void make(int l, int r, int &now) //建树
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    make(l, mid, ns[now].lc);
    make(mid + 1, r, ns[now].rc);
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void pushdown(int now, int cnt) //下发tag给子节点
{
    ns[now].v += ns[now].tag * cnt;
    ns[ns[now].lc].tag += ns[now].tag;
    ns[ns[now].rc].tag += ns[now].tag;
    ns[now].tag = 0;
}
void edit(int l, int r, int now, int x, int y, long long k) //区域修改
{
    if (l == x && r == y) //找到目标[x,y]区域
    {
        ns[now].tag += k;
        pushdown(now, r - l + 1);
        return;
    }
    pushdown(now, r - l + 1);
    int mid = (l + r) >> 1;
    if (y >= l && x <= mid)
    {
        edit(l, mid, ns[now].lc, max(x, l), min(y, mid), k);
        ns[now].v += k * (min(y, mid) - max(x, l) + 1); //下层节点值有修改 上层需更新
    }
    if (y >= mid + 1 && x <= r)
    {
        edit(mid + 1, r, ns[now].rc, max(x, mid + 1), min(y, r), k);
        ns[now].v += k * (min(y, r) - max(x, mid + 1) + 1);
    }
}
long long findxy(int l, int r, int now, int x, int y) //区域查询
{
    pushdown(now, r - l + 1);
    if (l == x && r == y)
    {
        return ns[now].v;
    }
    int mid = (l + r) >> 1;
    long long ans = 0;
    if (y >= l && x <= mid)
    {
        ans += findxy(l, mid, ns[now].lc, max(x, l), min(y, mid));
    }
    if (y >= mid + 1 && x <= r)
    {
        ans += findxy(mid + 1, r, ns[now].rc, max(x, mid + 1), min(y, r));
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    make(1, n, root);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            long long k;
            cin >> k;
            edit(1, n, root, x, y, k);
        }
        else
        {
            cout << findxy(1, n, root, x, y) << endl;
        }
    }
    return 0;
}