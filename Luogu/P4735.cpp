#include <algorithm>
#include <iostream>
using namespace std;
#define MX 300005
int n, m, pos, res, mx = 25, tx[MX * 2], root[MX * 2], num[30];
struct Node
{
    int lc, rc, t;
};
Node ns[100 * MX];
void edit(int old, int &now, int k)
{
    now = ++pos;
    ns[now] = ns[old];
    ns[now].t++;
    if (k == 0)
    {
        return;
    }
    if (num[k] == 0)
    {
        edit(ns[old].lc, ns[now].lc, k - 1);
    }
    else
    {
        edit(ns[old].rc, ns[now].rc, k - 1);
    }
}
void query(int old, int now, int k)
{
    if (k == 0)
    {
        return;
    }
    if ((ns[ns[now].rc].t - ns[ns[old].rc].t == 0 && num[k] == 1) || (ns[ns[now].lc].t - ns[ns[old].lc].t > 0 && num[k] == 0))
    {
        res = res * 2;
        query(ns[old].lc, ns[now].lc, k - 1);
    }
    else
    {
        res = res * 2 + 1;
        query(ns[old].rc, ns[now].rc, k - 1);
    }
}
int main()
{
    cin >> n >> m;
    edit(root[0], root[1], mx); // 整体右移一轮
    for (int i = 2; i <= n + 1; i++)
    {
        int a;
        cin >> a;
        tx[i] = tx[i - 1] ^ a;
        int v = tx[i];
        for (int j = 1; j <= mx; j++)
        {
            num[j] = v % 2;
            v /= 2;
        }
        edit(root[i - 1], root[i], mx);
    }
    n++;
    for (int i = 1; i <= m; i++)
    {
        char opt;
        int l, r, x;
        cin >> opt >> l;
        if (opt == 'A')
        {
            n++;
            tx[n] = tx[n - 1] ^ l;
            int v = tx[n];
            for (int j = 1; j <= mx; j++)
            {
                num[j] = v % 2;
                v /= 2;
            }
            edit(root[n - 1], root[n], mx);
        }
        else
        {
            cin >> r >> x;
            int v = tx[n] ^ x;
            for (int j = 1; j <= mx; j++)
            {
                num[j] = 1 - (v % 2);
                v /= 2;
            }
            res = 0;
            query(root[l - 1], root[r], mx);
            cout << (res ^ x ^ tx[n]) << '\n';
        }
    }
    return 0;
}