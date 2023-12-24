#include <iostream>
using namespace std;
struct Node
{
    long long v, tag, sz;
};
Node ns[400005];
void edit(int l, int r, long long ex)
{
    long long lsz = 0, rsz = 0; // 当前左右累计个数
    l--, r++;
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0) // 左端点l是左儿子，那么右儿子l + 1在范围内
        {
            lsz += ns[l + 1].sz;
            ns[l + 1].v += ns[l + 1].sz * ex, ns[l + 1].tag += ex;
        }
        if (r % 2 == 1) // 右端点r是右儿子，那么左儿子r - 1在范围内
        {
            rsz += ns[r - 1].sz;
            ns[r - 1].v += ns[r - 1].sz * ex, ns[r - 1].tag += ex;
        }
        l /= 2, r /= 2;
        ns[l].v += lsz * ex, ns[r].v += rsz * ex;
    }
    while (l != 1) // 维护至顶端
    {
        l /= 2;
        ns[l].v += (lsz + rsz) * ex;
    }
}
long long query(int l, int r)
{
    long long lsz = 0, rsz = 0, ans = 0;
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
int main()
{
    int n, m, base = 1;
    cin >> n >> m;
    while (base < n + 2)
    {
        base *= 2;
    }
    for (int i = 1; i <= n; i++)
    {
        long long x, now = i + base;
        cin >> x;
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