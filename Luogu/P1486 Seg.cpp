#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int lc, rc, v, tag;
};
Node ns[600005];
int n, lmt, ex, root, pos, tot, op[300005][2];
vector<int> ys;
void maketree(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
}
void pushdown(int now)
{
    if (ns[now].tag)
    {
        ns[ns[now].lc].v = ns[ns[now].rc].v = 0;
        ns[ns[now].lc].tag = ns[ns[now].rc].tag = 1;
        ns[now].tag = 0;
    }
}
void edit(int now, int l, int r, int x, int k)
{
    if (l == r)
    {
        ns[now].v += k;
        return;
    }
    pushdown(now);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, k);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, x, k);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void cl(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        ns[now].v = 0, ns[now].tag = 1;
        return;
    }
    pushdown(now);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        cl(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        cl(ns[now].rc, mid + 1, r, x, y);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
int query(int now, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    pushdown(now);
    int mid = (l + r) / 2;
    if (ns[ns[now].lc].v >= k)
    {
        return query(ns[now].lc, l, mid, k);
    }
    else
    {
        return query(ns[now].rc, mid + 1, r, k - ns[ns[now].lc].v);
    }
}
int main()
{
    cin >> n >> lmt;
    ys.push_back(0), ys.push_back(lmt);
    for (int i = 1; i <= n; i++)
    {
        char opt;
        cin >> opt >> op[i][1];
        if (opt == 'I')
        {
            op[i][0] = 1;
            ys.push_back(op[i][1] - ex);
        }
        else if (opt == 'A')
        {
            op[i][0] = 2;
            ex += op[i][1];
            ys.push_back(lmt - ex);
        }
        else if (opt == 'S')
        {
            op[i][0] = 3;
            ex -= op[i][1];
            ys.push_back(lmt - ex);
        }
    }
    sort(ys.begin(), ys.end()), ex = 0;
    maketree(root, 1, n);
    for (int i = 1; i <= n; i++)
    {
        if (op[i][0] == 1)
        {
            if (op[i][1] < lmt)
            {
                continue;
            }
            int pos = lower_bound(ys.begin(), ys.end(), op[i][1] - ex) - ys.begin() + 1;
            edit(root, 1, n, pos, 1);
        }
        else if (op[i][0] == 2)
        {
            ex += op[i][1];
        }
        else if (op[i][0] == 3)
        {
            ex -= op[i][1];
            int pos = lower_bound(ys.begin(), ys.end(), lmt - ex) - ys.begin();
            if (pos == 0)
            {
                continue;
            }
            tot += ns[root].v;
            cl(root, 1, n, 1, pos);
            tot -= ns[root].v;
        }
        else
        {
            if (op[i][1] > ns[root].v)
            {
                cout << -1 << endl;
                continue;
            }
            op[i][1] = ns[root].v - op[i][1] + 1;
            cout << ys[query(root, 1, n, op[i][1]) - 1] + ex << endl;
        }
    }
    cout << tot << endl;
    return 0;
}