#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc, v;
};
Node ns[400005];
int n, root, pos, ys[200005], op[100005][2];
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
void edit(int now, int l, int r, int x, int ex)
{
    if (l == r)
    {
        ns[now].v += ex;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, ex);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, x, ex);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
int query3(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    int mid = (l + r) / 2, sum = 0;
    if (x <= mid)
    {
        sum += query3(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        sum += query3(ns[now].rc, mid + 1, r, x, y);
    }
    return sum;
}
int query4(int now, int l, int r, int x)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if (ns[ns[now].lc].v >= x)
    {
        return query4(ns[now].lc, l, mid, x);
    }
    else
    {
        return query4(ns[now].rc, mid + 1, r, x - ns[ns[now].lc].v);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op[i][0] >> op[i][1];
        ys[i] = op[i][1];
        ys[n + i] = op[i][1] - 1;
    }
    n *= 2;
    maketree(root, 1, n);
    sort(ys + 1, ys + n + 1);
    for (int i = 1; i <= n / 2; i++)
    {
        if (op[i][0] != 4)
        {
            op[i][1] = lower_bound(ys + 1, ys + 1 + n, op[i][1]) - ys;
        }
        if (op[i][0] == 1)
        {
            edit(root, 1, n, op[i][1], 1);
        }
        else if (op[i][0] == 2)
        {
            edit(root, 1, n, op[i][1], -1);
        }
        else if (op[i][0] == 3)
        {
            cout << query3(root, 1, n, 1, op[i][1] - 1) + 1 << "\n";
        }
        else if (op[i][0] == 4)
        {
            cout << ys[query4(root, 1, n, op[i][1])] << "\n";
        }
        else if (op[i][0] == 5)
        {
            int a = ns[root].v - query3(root, 1, n, op[i][1], n);
            cout << ys[query4(root, 1, n, a)] << "\n";
        }
        else
        {
            int a = query3(root, 1, n, 1, op[i][1]) + 1;
            cout << ys[query4(root, 1, n, a)] << "\n";
        }
    }
    return 0;
}