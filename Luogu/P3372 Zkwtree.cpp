#include <iostream>
using namespace std;
struct Node
{
    long long tag, v, sz;
};
Node ns[30];
void edit(int l, int r, long long add)
{
    l--, r++;
    long long lsz = 0, rsz = 0;
    while (l / 2 != r / 2)
    {
        if (l == l / 2 * 2) //l为左子节点
        {
            ns[l / 2 * 2 + 1].tag += add;
            lsz += ns[l / 2 * 2 + 1].sz;
        }
        if (r == r / 2 * 2 + 1)
        {
            ns[r / 2 * 2].tag += add;
            rsz += ns[r / 2 * 2].sz;
        }
        l /= 2, r /= 2;
        ns[l].v += lsz * add;
        ns[r].v += rsz * add;
    }
    while (l / 2)
    {
        l /= 2;
        ns[l].v += (lsz + rsz) * add;
    }
}
long long count(int l, int r)
{
    l--, r++;
    long long tot = 0, lsz = 0, rsz = 0;
    while (l / 2 != r / 2)
    {
        if (l == l / 2 * 2)
        {
            tot += ns[l / 2 * 2 + 1].v + ns[l / 2 * 2 + 1].tag * ns[l / 2 * 2 + 1].sz;
            lsz += ns[l / 2 * 2 + 1].sz;
        }
        if (r == r / 2 * 2 + 1)
        {
            tot += ns[r / 2 * 2].v + ns[r / 2 * 2].tag * ns[r / 2 * 2].sz;
            rsz += ns[r / 2 * 2].sz;
        }
        l /= 2, r /= 2;
        tot += lsz * ns[l].tag + rsz * ns[r].tag;
    }
    while (l / 2)
    {
        l /= 2;
        tot += (lsz + rsz) * ns[l].tag;
    }
    return tot;
}

int main()
{
    int n, m, st = 1;
    cin >> n >> m;
    while (st <= n + 1)
    {
        st *= 2;
    }
    for (int i = st + 1; i <= st + n; i++)
    {
        cin >> ns[i].v;
        ns[i].sz = 1;
        int pos = i / 2;
        while (pos)
        {
            ns[pos].sz += ns[i].sz;
            ns[pos].v += ns[i].v;
            pos /= 2;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        long long k;
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            edit(x + st, y + st, k);
        }
        else
        {
            cout << count(x + st, y + st) << endl;
        }
    }
    return 0;
}