#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int gd, lc, rc;
};
Node ns[160005];
struct Edge
{
    double k, b;
};
Edge es[100005];
int n, root, ans, sol, epos, npos;
int h(int num, int mod) { return (num + ans - 1) % mod + 1; }
double cnt(int id, int p)
{
    return es[id].k * p + es[id].b;
}
void maketree(int &now, int l, int r)
{
    now = ++npos;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
}
void update(int now, int l, int r, int x, int y, int nid)
{
    if (now == 0)
    {
        return;
    }
    int mid = (l + r) / 2, id = ns[now].gd;
    if (x <= l && y >= r)
    {
        if (cnt(nid, mid) > cnt(id, mid))
        {
            ns[now].gd = nid;
            if (cnt(nid, l) < cnt(id, l))
            {
                update(ns[now].lc, l, mid, l, mid, id);
            }
            else if (cnt(nid, r) < cnt(id, r))
            {
                update(ns[now].rc, mid + 1, r, mid + 1, r, id);
            }
        }
        else
        {
            if (cnt(nid, l) > cnt(id, l))
            {
                update(ns[now].lc, l, mid, l, mid, nid);
            }
            else if (cnt(nid, r) > cnt(id, r))
            {
                update(ns[now].rc, mid + 1, r, mid + 1, r, nid);
            }
        }
    }
    else
    {
        if (x <= mid)
        {
            update(ns[now].lc, l, mid, x, y, nid);
        }
        if (mid < y)
        {
            update(ns[now].rc, mid + 1, r, x, y, nid);
        }
    }
}
void query(int now, int l, int r, int p)
{
    if (es[ns[now].gd].k * p + es[ns[now].gd].b >= es[sol].k * p + es[sol].b)
    {
        sol = ns[now].gd;
    }
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    p <= mid ? query(ns[now].lc, l, mid, p) : query(ns[now].rc, mid + 1, r, p);
}
int main()
{
    cin >> n;
    maketree(root, 1, 40000);
    while (n--)
    {
        int opt;
        cin >> opt;
        if (opt == 0)
        {
            int p;
            cin >> p;
            p = h(p, 39989);
            sol = 0;
            query(root, 1, 40000, p);
            ans = sol;
            cout << ans << endl;
        }
        else
        {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            x0 = h(x0, 39989), x1 = h(x1, 39989), y0 = h(y0, 1e9), y1 = h(y1, 1e9);
            if (x1 < x0)
            {
                swap(x0, x1), swap(y0, y1);
            }
            ++epos;
            x1 == x0 ? es[epos].k = 0, es[epos].b = max(y0, y1) : es[epos].k = 1.0 * (y1 - y0) / (x1 - x0), es[epos].b = y1 - es[epos].k * x1;
            update(root, 1, 40000, x0, x1, epos);
        }
    }
    return 0;
}