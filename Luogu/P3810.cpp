#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int a, b, c, ans, cnt;
};
Node ns[MX];
int ans[MX], bta[MX * 2], n, k, pos;
bool cmpA(Node x, Node y)
{
    if (x.a == y.a)
    {
        if (x.b == y.b)
        {
            return x.c < y.c;
        }
        return x.b < y.b;
    }
    return x.a < y.a;
}
bool cmpB(Node x, Node y)
{
    if (x.b == y.b)
    {
        return x.c < y.c;
    }
    return x.b < y.b;
}
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    while (x <= k)
    {
        bta[x] += v;
        x += lowbit(x);
    }
}
int query(int x)
{
    int tot = 0;
    while (x)
    {
        tot += bta[x];
        x -= lowbit(x);
    }
    return tot;
}
void cdq(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    cdq(l, mid), cdq(mid + 1, r);
    sort(ns + l, ns + mid + 1, cmpB), sort(ns + mid + 1, ns + r + 1, cmpB);
    int p1 = l;
    for (int p2 = mid + 1; p2 <= r; p2++)
    {
        while (p1 <= mid && ns[p1].b <= ns[p2].b)
        {
            add(ns[p1].c, ns[p1].cnt);
            p1++;
        }
        ns[p2].ans += query(ns[p2].c);
    }
    while (p1 > l)
    {
        p1--;
        add(ns[p1].c, -ns[p1].cnt);
    }
}
int main()
{
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
            ns[++pos] = Node{ns[i].a, ns[i].b, ns[i].c, 0, t}, t = 1;
        }
    }
    cdq(1, pos);
    for (int i = 1; i <= n; i++)
    {
        ans[ns[i].ans + ns[i].cnt - 1] += ns[i].cnt;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
// TAG: CDQ分治 三维偏序 树状数组