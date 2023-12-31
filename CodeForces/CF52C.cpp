#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    long long v, tag;
    int lc, rc;
};
Node ns[800005];
int n, m, pos, root, a[200005];
string s;
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    ns[now].v = min(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
void pushdown(int now, int l, int r)
{
    ns[ns[now].lc].v += ns[now].tag, ns[ns[now].rc].v += ns[now].tag;
    ns[ns[now].lc].tag += ns[now].tag, ns[ns[now].rc].tag += ns[now].tag;
    ns[now].tag = 0;
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    long long ans = 1e18;
    if (x <= mid)
    {
        ans = min(ans, query(ns[now].lc, l, mid, x, y));
    }
    if (y > mid)
    {
        ans = min(ans, query(ns[now].rc, mid + 1, r, x, y));
    }
    return ans;
}
void edit(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        ns[now].v += k, ns[now].tag += k;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    ns[now].v = min(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init(root, 1, n);
    cin >> m;
    getline(cin, s);
    for (int i = 1; i <= m; i++)
    {
        getline(cin, s);
        while (s.back() > '9' || s.back() < '0')
        {
            s.pop_back();
        }
        s += ' ';
        int p = s.find(' ');
        long long l = stoll(s.substr(0, p));
        int pre = p + 1;
        p = s.find(' ', p + 1);
        long long r = stoll(s.substr(pre, p - pre));
        long long k = 1e9;
        if (p != (int)s.size() - 1)
        {
            k = stoll(s.substr(p + 1));
        }
        l++, r++;
        if (k == 1e9)
        {
            if (l > r)
            {
                cout << min(query(root, 1, n, l, n), query(root, 1, n, 1, r)) << endl;
            }
            else
            {
                cout << query(root, 1, n, l, r) << endl;
            }
        }
        else
        {
            if (l > r)
            {
                edit(root, 1, n, l, n, k);
                edit(root, 1, n, 1, r, k);
            }
            else
            {
                edit(root, 1, n, l, r, k);
            }
        }
    }
    return 0;
}
// TAG: 线段树 最值 环形