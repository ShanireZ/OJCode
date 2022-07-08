#include <iostream>
using namespace std;
struct Node
{
    long long v, tag;
    int sz;
};
Node ns[400005];
int base = 1, n, m;
void edit(int l, int r, long long ex)
{
    int lsz = 0, rsz = 0;
    l--, r++;
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
        {
            lsz += ns[l + 1].sz;
            ns[l + 1].v += ns[l + 1].sz * ex, ns[l + 1].tag += ex;
        }
        if (r % 2 == 1)
        {
            rsz += ns[r - 1].sz;
            ns[r - 1].v += ns[r - 1].sz * ex, ns[r - 1].tag += ex;
        }
        l /= 2, r /= 2;
        ns[l].v += lsz * ex, ns[r].v += rsz * ex;
    }
    while (l != 1)
    {
        l /= 2;
        ns[l].v += (lsz + rsz) * ex;
    }
}
long long query(int l, int r)
{
    int lsz = 0, rsz = 0;
    long long ans = 0;
    l--, r++;
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
        {
            lsz += ns[l + 1].sz, ans += ns[l + 1].v;
        }
        if (r % 2 == 1)
        {
            rsz += ns[r - 1].sz, ans += ns[r - 1].v;
        }
        l /= 2, r /= 2;
        ans += lsz * ns[l].tag + rsz * ns[r].tag;
    }
    while (l != 1)
    {
        l /= 2;
        ans += ns[l].tag * (lsz + rsz);
    }
    return ans;
}
void edit1(int pos, long long ex)
{
    while (pos)
    {
        ns[pos].v += ex;
        pos /= 2;
    }
}
int main()
{
    cin >> n >> m;
    while (base <= n + 1)
    {
        base *= 2;
    }
    for (int i = base + 1; i <= base + n; i++)
    {
        long long x;
        cin >> x;
        int now = i;
        while (now)
        {
            ns[now].v += x, ns[now].sz += 1;
            now /= 2;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            long long k;
            cin >> k;
            edit(x + base, y + base, k);
        }
        else
        {
            cout << query(x + base, y + base) << endl;
        }
    }
    return 0;
}