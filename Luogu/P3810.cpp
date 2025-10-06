#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int a, b, c, t, cnt;
};
Node ns[100005];
bool cmp1(Node x, Node y)
{
    if (x.a == y.a)
    {
        return x.b == y.b ? x.c < y.c : x.b < y.b;
    }
    return x.a < y.a;
}
bool cmp2(Node x, Node y)
{
    return x.b == y.b ? x.c < y.c : x.b < y.b;
}
int tr[200005], ans[100005], n, k, pos;
void edit(int now, int ex)
{
    while (now <= k)
    {
        tr[now] += ex;
        now += (now & -now);
    }
}
int query(int now)
{
    int res = 0;
    while (now)
    {
        res += tr[now];
        now -= (now & -now);
    }
    return res;
}
void cdq(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    cdq(l, mid), cdq(mid + 1, r);
    sort(ns + l, ns + mid + 1, cmp2);
    sort(ns + mid + 1, ns + r + 1, cmp2);
    int p1 = l;
    for (int p2 = mid + 1; p2 <= r; p2++)
    {
        while (ns[p1].b <= ns[p2].b && p1 <= mid)
        {
            edit(ns[p1].c, ns[p1].t);
            p1++;
        }
        ns[p2].cnt += query(ns[p2].c);
    }
    for (int i = p1 - 1; i >= l; i--)
    {
        edit(ns[i].c, -ns[i].t);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].a >> ns[i].b >> ns[i].c;
    }
    sort(ns + 1, ns + 1 + n, cmp1);
    for (int i = 1, t = 1; i <= n; i++)
    {
        if (ns[i].a != ns[i + 1].a || ns[i].b != ns[i + 1].b || ns[i].c != ns[i + 1].c)
        {
            ns[++pos] = {ns[i].a, ns[i].b, ns[i].c, t, 0}, t = 1;
        }
        else
        {
            t++;
        }
    }
    cdq(1, pos);
    for (int i = 1; i <= pos; i++)
    {
        ns[i].cnt += ns[i].t - 1;
        ans[ns[i].cnt] += ns[i].t;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}