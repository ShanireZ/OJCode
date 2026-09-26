#include <bits/stdc++.h>
using namespace std;
#define MX 20000505
#define LC (ns[now].lc)
#define RC (ns[now].rc)
#define MID (l + r) / 2
struct SS
{
    unsigned long long v, lc, rc, tag;
} ns[MX];
unsigned long long n, m, root, pos;
void pushdown(unsigned long long now, int l, int r)
{
    if (LC == 0)
    {
        LC = ++pos;
    }
    if (RC == 0)
    {
        RC = ++pos;
    }
    ns[LC].v += (MID - l + 1) * ns[now].tag;
    ns[RC].v += (r - MID) * ns[now].tag;
    ns[LC].tag += ns[now].tag;
    ns[RC].tag += ns[now].tag;
    ns[now].tag = 0;
}
void edit(unsigned long long &now, int l, int r, int x, int y, unsigned long long k)
{
    if (now == 0)
    {
        now = ++pos;
    }
    if (x <= l && r <= y)
    {
        ns[now].v += (r - l + 1) * k;
        ns[now].tag += k;
        return;
    }
    pushdown(now, l, r);
    if (x <= MID)
    {
        edit(LC, l, MID, x, y, k);
    }
    if (y > MID)
    {
        edit(RC, MID + 1, r, x, y, k);
    }
    ns[now].v = ns[LC].v + ns[RC].v;
}
unsigned long long query(unsigned long long &now, int l, int r, int x, int y)
{
    if (now == 0)
    {
        now = ++pos;
    }
    if (x <= l && r <= y)
    {
        return ns[now].v;
    }
    unsigned long long tot = 0;
    pushdown(now, l, r);
    if (x <= MID)
    {
        tot += query(LC, l, MID, x, y);
    }
    if (y > MID)
    {
        tot += query(RC, MID + 1, r, x, y);
    }
    return tot;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        unsigned long long o, x, y, k;
        cin >> o >> x >> y;
        if (o == 1)
        {
            cin >> k;
            edit(root, 1, n, x, y, k);
        }
        else
        {
            cout << query(root, 1, n, x, y) + (x + y) * (y - x + 1) / 2 << endl;
        }
    }
    return 0;
}