#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int a, b, c, t, res;
};
Node ns[100005];
int ts[200005], ans[100005], n, k, pos;
void edit(int x, int ex)
{
    while (x <= k)
    {
        ts[x] += ex;
        x += (x & -x);
    }
}
int query(int x)
{
    int res = 0;
    while (x)
    {
        res += ts[x];
        x -= (x & -x);
    }
    return res;
}
bool cmpA(Node a, Node b)
{
    if (a.a == b.a)
    {
        if (a.b == b.b)
        {
            return a.c < b.c;
        }
        return a.b < b.b;
    }
    return a.a < b.a;
}
bool cmpB(Node a, Node b)
{
    if (a.b == b.b)
    {
        return a.c < b.c;
    }
    return a.b < b.b;
}
void cdq(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid), cdq(mid + 1, r);
    sort(ns + l, ns + mid + 1, cmpB), sort(ns + mid + 1, ns + r + 1, cmpB);
    int p1 = l, p2 = mid + 1;
    while (p2 <= r)
    {
        while (p1 <= mid && ns[p2].b >= ns[p1].b)
        {
            edit(ns[p1].c, ns[p1].t);
            p1++;
        }
        ns[p2].res += query(ns[p2].c);
        p2++;
    }
    while (p1 > l)
    {
        p1--;
        edit(ns[p1].c, -ns[p1].t);
    }
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].a >> ns[i].b >> ns[i].c;
    }
    sort(ns + 1, ns + n + 1, cmpA);
    for (int i = 1, t = 1; i <= n; i++)
    {
        if (ns[i].a == ns[i + 1].a && ns[i].b == ns[i + 1].b && ns[i].c == ns[i + 1].c)
        {
            t++;
        }
        else
        {
            ns[++pos] = Node{ns[i].a, ns[i].b, ns[i].c, t, 0};
            t = 1;
        }
    }
    cdq(1, pos);
    for (int i = 1; i <= pos; i++)
    {
        int x = ns[i].t - 1 + ns[i].res;
        ans[x] += ns[i].t;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}